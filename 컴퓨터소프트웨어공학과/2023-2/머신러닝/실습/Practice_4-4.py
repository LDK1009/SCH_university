from sklearn.datasets import fetch_openml
from sklearn.neural_network import MLPClassifier
import matplotlib.pyplot as plt
import numpy as np

mnist=fetch_openml('mnist_784')
mnist.data=mnist.data/255.0
x_train=mnist.data[:60000]; x_test=mnist.data[60000:]
y_train=np.int16(mnist.target[:60000]); y_test=np.int16(mnist.target[60000:])


#mlp분류 모델로 학습
mlp=MLPClassifier(hidden_layer_sizes=(100), learning_rate_init=0.001, batch_size=32, max_iter=300, solver='sgd', verbose=True)
mlp.fit(x_train, y_train)

#예측
res = mlp.predict(x_test)

#혼동 행렬
conf = np.zeros((10,10)) #10*10 행렬을 만들고 0으로 모두 초기화
for i in range(len(res)):
    conf[res[i]][y_test[i]]+=1 
print(conf)

#정확도
no_correct=0
for i in range(10):
    no_correct+=conf[i][i]
accuracy=no_correct/len(res)
print("테스트 집합에 대한 정확률은", accuracy*100, "%입니다.")
