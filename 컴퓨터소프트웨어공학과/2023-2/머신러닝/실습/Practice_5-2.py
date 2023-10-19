# 필요한 라이브러리 불러오기
import tensorflow as tf
import numpy as np

# TensorFlow를 사용하여 [2, 3] 형태의 텐서를 생성. 값은 0과 1 사이의 균일한 분포를 갖는다.
t = tf.random.uniform([2,3], 0, 1)
# NumPy를 사용하여 [2, 3] 형태의 배열을 생성. 값은 0과 1 사이의 균일한 분포를 갖는다.
n = np.random.uniform(0, 1, [2,3])

# 생성된 텐서와 배열 출력
print("tensorflow로 생성한 텐서: \n", t, "\n")
print("numpy로 생성한 텐서: \n", n, "\n")

# 두 텐서(또는 배열)를 더하기
res = t + n
print("덧셈 결과: \n", res)
