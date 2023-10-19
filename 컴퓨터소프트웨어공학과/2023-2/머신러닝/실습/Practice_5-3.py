# 필요한 라이브러리 불러오기
import tensorflow as tf
import tensorflow.keras.datasets as ds

# MNIST 데이터셋 불러오기 (손으로 쓴 숫자 이미지 데이터셋)
(x_train, y_train), (x_test, y_test) = ds.mnist.load_data()

# MNIST 데이터셋의 레이블을 원-핫 인코딩 벡터로 변환하기
yy_train = tf.one_hot(y_train, 10 ,dtype=tf.int8)

# MNIST 데이터셋 구성 요소의 형태 출력하기
print("MNIST: ", x_train.shape, y_train.shape, yy_train.shape)

# CIFAR-10 데이터셋 불러오기 (10개 클래스의 이미지 데이터셋, 예: 자동차, 새 등)
(x_train, y_train), (x_test, y_test) = ds.cifar10.load_data()

# CIFAR-10 데이터셋의 레이블을 원-핫 인코딩 벡터로 변환하기
yy_train = tf.one_hot(y_train, 10 ,dtype=tf.int8)

# CIFAR-10 데이터셋 구성 요소의 형태 출력하기
print("CIFAR-10: ", x_train.shape, y_train.shape, yy_train.shape)

# 보스턴 주택 데이터셋 불러오기 (보스턴의 주택 가격 관련 데이터셋)
(x_train, y_train), (x_test, y_test) = ds.boston_housing.load_data()

# 보스턴 주택 데이터셋 구성 요소의 형태 출력하기
print("Boston Housing: ", x_train.shape, y_train.shape)

# 로이터 데이터셋 불러오기 (46개의 다른 주제로 텍스트 분류 데이터셋)
(x_train, y_train), (x_test, y_test) = ds.reuters.load_data()

# 로이터 데이터셋 구성 요소의 형태 출력하기
print("Reuters: ", x_train.shape, y_train.shape)
