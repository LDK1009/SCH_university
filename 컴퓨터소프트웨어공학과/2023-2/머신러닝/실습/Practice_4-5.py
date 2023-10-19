# 필요한 라이브러리를 가져옵니다.
from sklearn import datasets
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split, validation_curve
import numpy as np
import matplotlib.pyplot as plt
import time

# 숫자 데이터셋을 불러옵니다.
digit = datasets.load_digits()

# 데이터셋을 훈련과 테스트 세트로 나눕니다 (훈련 60%, 테스트 40%)
x_train, x_test, y_train, y_test = train_test_split(digit.data, digit.target, train_size=0.6)

# 성능 측정을 위해 시작 시간을 기록합니다.
start = time.time()

# 지정된 하이퍼파라미터로 MLPClassifier를 생성합니다.
mlp = MLPClassifier(learning_rate_init=0.001, batch_size=32, max_iter=300, solver='sgd')

# 'hidden_layer_sizes' 하이퍼파라미터의 다양한 값에 대한 훈련 및 테스트 점수를 계산하기 위해 범위를 정의합니다.
prange = range(50, 1001, 50)  # 50에서 1000까지 50씩 증가

# 'hidden_layer_sizes'에 대한 다양한 값에 대한 훈련 및 테스트 점수를 계산하기 위해 validation_curve를 사용합니다.
train_score, test_score = validation_curve(mlp, x_train, y_train, param_name='hidden_layer_sizes', param_range=prange, cv=10, scoring="accuracy", n_jobs=4)

# 성능 측정을 위해 종료 시간을 기록합니다.
end = time.time()

# 하이퍼파라미터 최적화에 걸린 시간을 출력합니다.
print("하이퍼파라미터 최적화에 걸린 시간:", end - start, "초")

# 훈련 및 테스트 점수의 평균과 표준 편차를 계산합니다.
train_mean = np.mean(train_score, axis=1)
train_std = np.std(train_score, axis=1)
test_mean = np.mean(test_score, axis=1)
test_std = np.std(test_score, axis=1)

# 'hidden_layer_sizes'에 따른 훈련 및 테스트 점수를 그래프로 나타냅니다.
plt.plot(prange, train_mean, label="훈련 점수", color="r")
plt.plot(prange, test_mean, label="테스트 점수", color="b")
plt.fill_between(prange, train_mean - train_std, train_mean + train_std, alpha=0.2, color="r")
plt.fill_between(prange, test_mean - test_std, test_mean + test_std, alpha=0.2, color="b")
plt.legend(loc="best")
plt.title("MLP와 함께의 검증 곡선")
plt.xlabel("은닉 노드 수")
plt.ylabel("정확도")
plt.ylim(0.9, 1.01)
plt.grid(axis="both")
plt.show()

# 가장 높은 테스트 점수를 얻은 은닉 노드 수를 찾습니다.
best_number_nodes = prange[np.argmax(test_mean)]
print("\n최적의 은닉 노드 수:", best_number_nodes, "\n")

# 최적 하이퍼파라미터 설정을 사용하여 MLP 분류기를 생성합니다.
mlp = MLPClassifier(hidden_layer_sizes=(best_number_nodes,), learning_rate_init=0.001, batch_size=32, max_iter=300, solver='sgd', verbose=True)

# 훈련 데이터에 MLP 분류기를 훈련시킵니다.
mlp.fit(x_train, y_train)

# 테스트 데이터에 대한 예측을 수행합니다.
res = mlp.predict(x_test)

# 모델의 성능을 분석하기 위한 혼동 행렬을 생성합니다.
confusion_matrix = np.zeros((10, 10))  # 모든 요소가 0인 10x10 행렬을 초기화합니다.
for i in range(len(res)):
    confusion_matrix[res[i]][y_test[i]] += 1

# 혼동 행렬을 출력합니다.
print("혼동 행렬:")
print(confusion_matrix)

# 테스트 세트에서 모델의 정확도를 계산합니다.
correct = 0
for i in range(10):
    correct += confusion_matrix[i][i]

accuracy = correct / len(res)
print("테스트 세트에서의 정확도:", accuracy * 100, "%")
