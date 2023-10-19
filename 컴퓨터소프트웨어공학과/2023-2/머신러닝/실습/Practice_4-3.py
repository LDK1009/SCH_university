# 필요한 모듈 및 패키지 가져오기
from sklearn import datasets
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
import numpy as np

# 숫자 이미지 데이터셋 불러오기
digit = datasets.load_digits()

# 데이터를 훈련 세트와 테스트 세트로 나누기 (60%를 훈련 세트로 사용)
x_train, x_test, y_train, y_test = train_test_split(digit.data, digit.target, train_size=0.6)

# MLP (Multi-Layer Perceptron) 분류기 초기화
mlp = MLPClassifier(
    hidden_layer_sizes=(100),       # 은닉층의 뉴런 수 설정
    learning_rate_init=0.001,       # 학습률 설정
    batch_size=32,                  # 미니배치 크기 설정
    max_iter=300,                   # 최대 반복 횟수 설정
    solver='sgd',                   # 최적화 알고리즘 설정 (확률적 경사 하강법)
    verbose=True                    # 학습 과정 출력 설정 (True: 출력 함)
)

# 훈련 데이터로 MLP 모델 훈련
mlp.fit(x_train, y_train)

# 테스트 데이터에 대한 예측 수행
res = mlp.predict(x_test)

# 오차 행렬 (confusion matrix) 초기화
conf = np.zeros((10, 10))  # 10x10 크기의 행렬을 만들고 0으로 초기화

# 오차 행렬 업데이트
for i in range(len(res)):
    conf[res[i]][y_test[i]] += 1

# 오차 행렬 출력
print(conf)

# 정확한 예측 수 초기화
no_correct = 0

# 각 클래스에 대한 정확한 예측 수를 누적
for i in range(10):
    no_correct += conf[i][i]

# 정확도 계산
accuracy = no_correct / len(res)

# 정확도 출력
print("테스트 집합에 대한 정확률은", accuracy * 100, "%입니다.")
