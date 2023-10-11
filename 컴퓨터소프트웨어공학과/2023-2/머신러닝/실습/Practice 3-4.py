from sklearn import datasets
from sklearn import svm

digit = datasets.load_digits() #학습 데이터

s=svm.SVC(gamma=0.1, C=10) #SVM 학습 모델
s.fit(digit.data, digit.target)  #훈련 데이터의 데이터와 레이블을 통해 SVM 학습 시킨다

new_d=[digit.data[0], digit.data[1], digit.data[2]] #새로운 데이터(테스트 데이터) 3개
res=s.predict(new_d) #테스트 데이터 3개의 예측값
print("예측값은", res) #예측된 레이블을 반환한다
print("참 값은", digit.target[0],digit.target[1],digit.target[2],) #참 값은 새로운 데이터들의 레이블이다.

res=s.predict(digit.data) #학습 데이터의 모든 예측값을 res에 담는다
correct = [i for i in range(len(res)) if res[i]==digit.target[i]] # 예측값과 참값이 같을 떄 즉, 예측이 정답일 때 배열에 해당 값을 담는다
accuracy=len(correct)/len(res) # 맞힌 데이터 수 / 전체 데이터 수 = 정확률
print("화소 특징을 사용했을 떄 정확률=", accuracy*100,"%") #위 코드의 정확률이 100%가 나오는 이유는 학습데이터의 예측값으로 정확률을 측정했기 때문이다.
#테스트 데이터로 수행해야 비로소 정확률이 나온다.