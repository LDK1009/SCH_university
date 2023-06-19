import matplotlib.pyplot as plt

initial_capital = 0  # 초기 자본 (단위: 10,000원)
initial_expense = 130  # 초기 소비 (단위: 10,000원)
monthly_expense = 44  # 월간 소비 (단위: 10,000원)
total_income = 0 + initial_capital # 누적 이익 + 초기 자본
total_expenses = 0 + initial_expense # 누적 소비 + 초기 소비

# 누적 소비 계산
def calculate_total_expenses(month):
    global total_expenses
    global initial_expense
    total_expenses = initial_expense + monthly_expense * month
    return total_expenses

# 누적 수익 계산
def calculate_income(c):
    global total_income
    income1 = 4 * c * 0.05  # 결제 수수료
    income2 = 0.008 * c * 0.03 * 0.7    # 광고 수익
    sum_income = income1 + income2  # 월간 수익
    total_income += sum_income
    return sum_income

# 월별 수익 계산
def calculate_monthly_income(month):
    consumer = 0
    if month == 0:
        consumer = 0
    elif month == 1:
        consumer = 100
    elif month == 2:
        consumer = 150
    elif month == 3:
        consumer = 200
    elif month == 4:
        consumer = 250
    elif month == 5:
        consumer = 300
    elif month == 6:
        consumer = 400
    elif month == 7:
        consumer = 500
    elif month == 8:
        consumer = 600
    elif month == 9:
        consumer = 700
    elif month == 10:
        consumer = 800
    elif month == 11:
        consumer = 900
    elif month == 12:
        consumer = 1000
    calculate_income(consumer)
    return total_income

def plot_break_even_graph():
    months = range(0, 13)
    cumulative_income = [calculate_monthly_income(month) for month in months]  # 단위 변환
    cumulative_losses = [calculate_total_expenses(month) for month in months]  # 누적 손해 계산

    plt.plot(months, cumulative_income, label='Cumulative Income')
    plt.plot(months, cumulative_losses, label='Cumulative Loss')
    plt.xlabel('Months')
    plt.ylabel('Amount (in 10,000 KRW)')
    plt.title('Break-Even Point')
    plt.legend()
    plt.grid(True)
    plt.xticks(range(0, 13, 1))  # x축 격자를 1단위로 설정
    plt.yticks(range(0, int(max(cumulative_income)+1), 100))


    plt.show()

plot_break_even_graph()
