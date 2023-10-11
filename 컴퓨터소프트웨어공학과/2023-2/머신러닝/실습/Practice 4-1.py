from sklearn.linear_model import Perceptron

#훈련 집합 구축
x=[[0,0,], [0,1], [1,0], [1,1]] #훈련 데이터의 특성(feature)을 담고 있는 리스트
y=[-1,1,1,1] #각 데이터 포인트에 대한 클래스 레이블(타겟)

#fit 함수로 Percecptron 학습
p=Perceptron()
p.fit(x,y)

#가중치(coef_)는 입력 특성(feature)과 연결된 값으로, 각 입력 특성에 대한 중요도를 나타냅니다.
#편향(intercept_)은 모델이 얼마나 쉽게 활성화되는지 조절합니다. 즉, 편향은 입력 특성이 모델에 미치는 영향을 조절하는 역할을 합니다.
print("학습된 퍼셉트론의 매개변수 : ", p.coef_, p.intercept_)
print("훈련집합에 대한 예측 : ", p.predict(x))
print("정확률 측정 : ", p.score(x,y)*100, "%")