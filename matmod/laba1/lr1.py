import math
import matplotlib.pyplot as plt


def get_func_derivative(x, y):
    return x * pow(math.e, -(x ** 2)) - 2 * x * y


def get_func(x):
    return pow(math.e, -(x ** 2)) * (x ** 2 / 2 + 1)


def get_k1(x, y, h):
    return h * get_func_derivative(x, y)


def get_k2(x, y, h):
    return h * get_func_derivative(x + h / 2, y + get_k1(x, y, h) / 2)


def get_k3(x, y, h):
    return h * get_func_derivative(x + h / 2, y + get_k2(x, y, h) / 2)


def get_k4(x, y, h):
    return h * get_func_derivative(x + h, y + get_k3(x, y, h))


def get_y_next_runge_kutta(x, y, h):
    return y + (get_k1(x, y, h) + 2 * get_k2(x, y, h) + 2 * get_k3(x, y, h) + get_k4(x, y, h)) / 6


def get_y_next_euler(x, y, h):
    return y + h * get_func_derivative(x, y)


def get_all_values(start_point, end_point, step, y_start_value):
    y_values_euler, y_values_runge_kutta, y_values_real = [y_start_value], [y_start_value], []

    x_values = []
    x_value = start_point
    y_value_runge_kutta = y_value_euler = y_start_value
    while x_value <= (end_point - step):
        y_value_euler = get_y_next_euler(x_value, y_value_euler, step)
        y_values_euler.append(y_value_euler)

        y_value_runge_kutta = get_y_next_runge_kutta(x_value, y_value_runge_kutta, step)
        y_values_runge_kutta.append(y_value_runge_kutta)

        y_value_real = get_func(x_value)
        y_values_real.append(y_value_real)

        x_values.append(x_value)
        x_value = round(x_value + step, 15)

    x_values.append(x_value)
    y_value_real = get_func(x_value)
    y_values_real.append(y_value_real)

    return x_values, y_values_euler, y_values_runge_kutta, y_values_real


def get_graph(x_values, y_values_euler, y_values_runge_kutta, y_values_real):
    plt.plot(x_values, y_values_euler, 'g', linewidth=1)
    plt.plot(x_values, y_values_runge_kutta, 'b', linewidth=1)
    plt.plot(x_values, y_values_real, 'r--')

    plt.title('График функции y(x)', fontsize=20, fontname='Times New Roman')
    plt.xlabel('x', color='gray')
    plt.ylabel('y', color='gray')
    plt.legend(['Вычисления по Эйлеру', 'Вычисление по Рунге-Кутту', 'Аналитический метод'], loc=0)

    plt.savefig('lr1.png')
    plt.show()

    print('Погрешность при вычислениях по Эйлеру:', abs(y_values_real[-1] - y_values_euler[-1]))
    print('Погрешность при вычислениях по Рунге-Кутту:', abs(y_values_real[-1] - y_values_runge_kutta[-1]))


def main():
    a, b = 0, 1
    y_0 = 1
    h = 0.05

    get_graph(*get_all_values(a, b, h, y_0))


if __name__ == '__main__':
    main()
