import numpy as np
import matplotlib.pyplot as plt


def ten_ones():
    ones = np.ones(10)
    print(ones)


def two_dim():
    zeroes = np.zeros(25).reshape(5,5)

    print(zeroes.shape)
    print(zeroes)


def three_dim():
    ones = np.ones(2*3*4).reshape(2,3,4)

    print(ones.shape)
    print(ones)


def random_test1():
    data = np.arange(25).reshape(5,5)
    print(data)

    sarake2 = data[:,2]
    rivi2 = data[2,:]
    JokaToinenRiviJaSarake = data[1:5:2,1:5:2]

    print(f"{sarake2=}")
    print(f"{rivi2=}")
    print(f"{JokaToinenRiviJaSarake=}")


def random_empty():
    random = np.random.rand(8)
    print(random)

    empty = np.empty((4,4))
    print(empty) # random arvoja koska ei alusteta


def arange_linspace():
    data = np.arange(0,20,2)
    print(data)

    linspace = np.linspace(0,5,10)
    print(linspace)


def data_slice():
    ones = np.arange(10,20)

    print(ones)
    print(ones[2])
    print(ones[4])
    print(ones[6])

    print(f"parilliset = {[i for i in ones if i in [10, 12, 14, 16, 18]]}")
    print(ones[::2])
    print(ones[-4:][::-1])



def data_insert():
    data = np.ones((2,3))
    data[0,:]=5
    data2 = np.vstack((data,[7,8,9]))
    data3 = np.hstack((data2,[[10],[11],[12]]))
    print(data)
    print(data2)
    print(data3)

def reshape():

    original = np.arange(15)
    reshape = original.reshape(3,5)

    print(original)
    print(reshape)


def numpy_func():
    data = np.random.randint(1,10, (3,4))

    print(data)
    print(np.mean(data, axis=0))
    print(np.mean(data, axis=1))
    print(np.max(data, axis=1))
    print(np.sum(data))


def broadcasting():
    fives = np.array([5 for i in range(9)]).reshape(3,3)
    fives = np.vstack((fives, [1,2,3]))
    fives = 2 * fives
    print(fives)


def three_dim_table():
    data = np.random.randn(2,3,4)
    print(data)
    print()
    print(data[0])
    data[0,:,:] = 0
    print()
    print(data[0])
    reshaped = data.reshape(6,4)
    print()
    print(reshaped)

    print(f"{np.std(data)= }")

def color_pic_numpy():
    kuva = np.zeros((256,256,3), dtype=np.uint8)
    kuva = np.linspace(0, 256, 256*256).reshape(256,256)

    kuva = np.array([[i for i in range(256)] for _j in range(256)])

    print(f"{kuva=}")
    # kuva[0:128, 0:128] = (255,0,0)
    # kuva[0:128, 128:] = (0,0,255)
    # kuva[128:, 0:128] = (0,255,0)
    # kuva[128:, 128:] = (128,128,128)
    # plt.figure(1)
    plt.imshow(kuva/255)
    plt.show()


if __name__ == "__main__":
    #ten_ones()
    #two_dim()
    #three_dim()
    #random_test1()
    #random_empty()
    #arange_linspace()
    #data_slice()
    #data_insert()
    #reshape()
    #numpy_func()
    #broadcasting()
    #three_dim_table()
    color_pic_numpy()
