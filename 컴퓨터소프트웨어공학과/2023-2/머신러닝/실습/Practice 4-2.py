# 필요한 모듈 및 패키지 가져오기
from sklearn import datasets
from sklearn.linear_model import Perceptron
from sklearn.model_selection import train_test_split
import numpy as np

# 숫자 이미지 데이터셋 불러오기
digit = datasets.load_digits()

# 데이터를 훈련 세트와 테스트 세트로 나누기 (60%를 훈련 세트로 사용)
x_train, x_test, y_train, y_test = train_test_split(digit.data, digit.target, train_size=0.6) 

# 퍼셉트론 모델 초기화
p = Perceptron(max_iter=100, eta0=0.001, verbose=0)
#퍼셉트론 알고리즘의 최대 반복 횟수 = 100
#학습률(가중치) 조절, 작은 값인 0.001
#로그 메시지 출력 여부 0으로 설정되어 있으므로 어떤 로그 메시지도 출력하지 않습니다. 값을 1로 설정하면 출력합니다

# 훈련 데이터로 퍼셉트론 모델 훈련
p.fit(x_train, y_train)

# 테스트 데이터에 대한 예측 수행
res = p.predict(x_test)

# 오차 행렬 (confusion matrix) 초기화
conf = np.zeros((10, 10))

# 오차 행렬 업데이트
for i in range(len(res)):
    conf[res[i]][y_test[i]] += 1

# 오차 행렬 출력
print(conf)

# 정확한 예측 수 초기화
correct = 0

# 각 클래스에 대한 정확한 예측 수를 누적
for i in range(10):
    correct += conf[i][i]

# 정확도 계산
accuracy = correct / len(res)

# 정확도 출력
print("테스트 집합에 대한 정확률은", accuracy * 100, "% 입니다")
