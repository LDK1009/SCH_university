from sklearn import datasets
from sklearn import svm
from sklearn.model_selection import train_test_split
import numpy as np

digit = datasets.load_digits() #데이터 셋 로드
#각 변수에 digit.data와 digit.target 값을 train값과 test값으로 나누어 대입한다. train_size를 통해 60%만 트레이닝 셋으로 활용
x_train, x_test, y_train, y_test=train_test_split(digit.data, digit.target, train_size=0.6)


s= svm.SVC(gamma=0.001)
s.fit(x_train, y_train) #트레이닝 데이터 부뉴 모델 학습

res = s.predict(x_test)

conf = np.zeros((10,10)) #10*10 행렬을 만들고 0으로 모두 초기화
for i in range(len(res)):
    conf[res[i]][y_test[i]]+=1 
print(conf)

no_correct=0
for i in range(10):
    no_correct+=conf[i][i]
accuracy=no_correct/len(res)
print("테스트 집합에 대한 정확률은", accuracy*100, "%입니다.")
