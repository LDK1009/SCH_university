from sklearn import datasets
from sklearn import svm
from sklearn.model_selection import train_test_split # 테스트 데이터
import numpy as np

digit = datasets.load_digits()
x_train, x_test, y_train, y_test=train_test_split(digit.data, digit.target, train_size=0.6) 
#주어진 데이터와 타겟을 60%의 학습 데이터와 40%의 테스트 데이터로 나눈다
#x_train은 학습데이터의 데이터 특징, y_train은 학습 데이터의 레이블 값이 들어있다
 
#svm의 분류 모델 SVC를 학습
s=svm.SVC(gamma=0.001)
s.fit(x_train, y_train) #훈련 데이터의 특징과 레이블을 학습 시킨다

res=s.predict(x_test)
print(res, "\n\n\n\n\n\n\n\n\n")
print(y_test)

#혼동 행렬
conf=np.zeros((10,10)) #10*10 행렬을 만든 후 0으로 초기화
for i in range(len(res)): #1부터 res 배열의 요소 개수만큼 반복
    conf[res[i]][y_test[i]]+=1 #정답이 3이라면 3열에 예측값을 표시한다. ex) 정답이 3인데 예측값이 1이라면 1행의 3열에 1을 더한다
print(conf)

correct=0
for i in range(10):
    correct+=conf[i][i]
accuracy=correct/len(res) #예측값과 참값이 같은 개수 / 테스트 데이터의 개수
print(len(res))
print("테스트 집합에 대한 정확률은", accuracy*100, "%입니다")
