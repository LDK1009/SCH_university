# 필요한 모듈 및 패키지 가져오기
from sklearn.datasets import fetch_openml
from sklearn.neural_network import MLPClassifier
import matplotlib.pyplot as plt
import numpy as np

# MNIST 데이터셋 로드 (손글씨 숫자 이미지 데이터셋)
mnist = fetch_openml('mnist_784')

# 이미지 데이터를 0-1 사이로 정규화(원-핫 인코딩)
mnist.data = mnist.data / 255.0

# 훈련 데이터와 테스트 데이터 분리
x_train = mnist.data[:60000]
x_test = mnist.data[60000:]
y_train = np.int16(mnist.target[:60000])
y_test = np.int16(mnist.target[60000:])

# MNIST 데이터셋을 이미 로드하고 이미지 데이터는 mnist.data에, 레이블은 mnist.target에 저장되어 있다.

# 훈련 데이터와 테스트 데이터를 나누기 위해 슬라이싱(Slicing)을 사용하여 데이터를 분할한다.
# mnist.data[:60000]은 처음 60,000개의 이미지 데이터를 선택하여 x_train에 저장한다.
# mnist.data[60000:]은 나머지 이미지 데이터를 선택하여 x_test에 저장한다.
# mnist.target[:60000]은 처음 60,000개의 레이블(숫자) 데이터를 선택하여 y_train에 저장한다.
# mnist.target[60000:]은 나머지 레이블 데이터를 선택하여 y_test에 저장한다.

# MLP (Multi-Layer Perceptron) 분류 모델 초기화
mlp = MLPClassifier(
    hidden_layer_sizes=(100),  # 은닉층의 뉴런 수 설정
    learning_rate_init=0.001,  # 학습률 설정
    batch_size=32,             # 미니배치 크기 설정
    max_iter=300,              # 최대 반복 횟수 설정
    solver='sgd',              # 최적화 알고리즘 설정 (확률적 경사 하강법)
    verbose=True               # 학습 과정 출력 설정 (True: 출력 함)
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
