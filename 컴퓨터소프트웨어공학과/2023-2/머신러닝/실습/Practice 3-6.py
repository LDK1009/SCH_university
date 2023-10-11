from sklearn import datasets
from sklearn import svm
from sklearn.model_selection import cross_val_score
import numpy as np

digit=datasets.load_digits()
s=svm.SVC(gamma=0.001)
accuracies=cross_val_score(s, digit.data, digit.target, cv=5) #SVC 모델로 5겹 교차검증

print(accuracies) #5겹 교차 검증에서 각 폴드(fold)에 대한 모델의 정확도가 포함되어 있습니다.
print("정확률(평균)=%0.3f, 표준편차=%0.3f" %(accuracies.mean()*100, accuracies.std()))
#mean은 평균 std는 표준편차