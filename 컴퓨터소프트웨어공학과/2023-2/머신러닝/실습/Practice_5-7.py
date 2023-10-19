import numpy as np
import tensorflow as tf
from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import Adam

# MNIST 데이터 로딩
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# reshape 함수를 사용하여 2차원 이미지 데이터를 1차원으로 변경
x_train = x_train.reshape(60000, 784)
x_test = x_test.reshape(10000, 784)

# float32 데이터 타입으로 변환한 후 [0,255] 범위를 [0,1] 범위로 정규화 (원-핫 인코딩)
x_train = x_train.astype(np.float32) / 255.0
x_test = x_test.astype(np.float32) / 255.0

# 레이블을 원핫 인코딩 형태로 변경
y_train = tf.keras.utils.to_categorical(y_train, 10)
y_test = tf.keras.utils.to_categorical(y_test, 10)


# 입력 노드의 수 설정: 784개 (MNIST 이미지는 28x28 픽셀이므로)
n_input = 784

# 첫 번째 은닉층의 노드 수 설정: 1024개
n_hidden = 1024

# 출력 노드의 수 설정: 10개 (MNIST 데이터셋은 0부터 9까지의 숫자를 분류하므로)
n_output = 10

# Sequential 모델 초기화 (순차적으로 레이어를 추가할 수 있는 모델)
mlp = Sequential()

# 첫 번째 Dense 레이어(완전 연결층) 추가: 1024개의 노드, tanh 활성화 함수 사용
# kernel_initializer로 가중치 초기화 방법을 'random_uniform'으로 설정
# bias_initializer로 편향 초기값을 0으로 설정
mlp.add(Dense(units=n_hidden, activation='tanh', input_shape=(n_input,), kernel_initializer='random_uniform', bias_initializer='zeros'))

# 두 번째 Dense 레이어(완전 연결층) 추가: 출력 레이어로, 10개의 노드, tanh 활성화 함수 사용
# kernel_initializer로 가중치 초기화 방법을 'random_uniform'으로 설정
# bias_initializer로 편향 초기값을 0으로 설정
mlp.add(Dense(units=n_output, activation='tanh', kernel_initializer='random_uniform', bias_initializer='zeros'))

#손실함수로 mse, 옵티마이저로 Adam 사용
mlp.compile(loss='mean_squared_error', optimizer=Adam(learning_rate=0.001), metrics=['accuracy'])

#학습 도중에 발생한 정보를 hist 객체에 저장해 두어 시각화에 활용한다
hist = mlp.fit(x_train, y_train, batch_size=256, epochs=10, validation_data=(x_test, y_test), verbose=2)

#정확률 측정
res = mlp.evaluate(x_test, y_test, verbose=0)
print("정확도:", res[1]*100)
