import encode

import numpy as np
import math
import matplotlib.pyplot as plt
import os
# import encode_k_windows


dist_txt_dict = {1:r'uniform_continous_test\uniform_continous_l{}.txt',
             2:r'uniform_discontinous_test\uniform_discontinous_l{}.txt',
             3:r'simulate_real_test\simulate_real_l{}.txt',
             4:r'normal_distribution.test\normal_distribution_l{}.txt'
             }

dict_encode_dict = {1:r'uniform_continous_test\uniform_continous_code_l{}.txt',
                    2:r'uniform_discontinous_test\uniform_discontinous_code_l{}.txt',
                    3:r'simulate_real_test\simulate_real_code_l{}.txt',
                    4:r'normal_distribution.test\normal_distribution_code_l{}.txt'
}

def model_element():
    x = np.arange(5, 20, 1)
    simulate_real_ratio = ratio_list_normal_sample(3,20)
    cnt = 0
    for i in range(0,len(simulate_real_ratio)-1):
        if(simulate_real_ratio[i] - simulate_real_ratio[i+1] < 0.01 ):
            if cnt == 0:
                shoulian = (i+5,simulate_real_ratio[i])
            cnt +=1 
        else:
            cnt  = 0
        if cnt == 3:
            break
    print(shoulian )
    print(simulate_real_ratio[0])

    plt.scatter(shoulian[0], shoulian[1], color='r')
    # plt.text(shoulian[0], shoulian[1] + 0.05, "convergence", fontsize = 10, color = 'r',verticalalignment= "center",horizontalalignment = "center")

    

    plt.plot(x,simulate_real_ratio ,label="simulate_real_ratio ",linestyle = ":")     
    plt.xlabel("log the size of message")
    plt.ylabel("compression ratio") 

    plt.title('the compress ratio with the size of message')
    plt.legend()   #打上标签
    plt.show()

def ratio_list_normal_sample(dist_n,x_l = 15):
    Tencoder = encode.Encoder()
    ratio_list = []
    for i in range(5,x_l):
        i = i 
        Tencoder.encodeFile(dist_txt_dict[dist_n].format(int(2**i)), dict_encode_dict[dist_n].format(int(2**i)))
        size_before =os.path.getsize( dist_txt_dict[dist_n].format(int(2**i)))
        size_after =os.path.getsize(dict_encode_dict[dist_n].format(int(2**i)))
        ratio = (size_after) / (size_before + 0.5 )
        ratio_list.append(ratio)
        # print(dist_txt_dict[dist_n].format(2**i) , "before encode: {}".format(size_before),"byte;\n after encode: {}".format(size_after),"byte\n; compress ratio is {}".format(ratio))

    return ratio_list

def cal_coverage_effience(ratio_list):
    launch = ratio_list[0]
    cnt = 0
    for i in range(0,len(ratio_list)-1):
        if(ratio_list[i] - ratio_list[i+1] < 0.01 ):
            if cnt == 0:
                shoulian = (i+5,ratio_list[i])
            cnt +=1 
        else:
            cnt  = 0
        if cnt == 2:
            break
    if cnt != 2:
        shoulian = (0,0)
    coverage_volcity = float( 1-  shoulian[1]) / (shoulian[0] + 0.001)

    return (shoulian,coverage_volcity,launch)

def draw_compress_ratio_with_log_size_normal_sample():
    x = np.arange(5, 15, 1)
    uniform_continous_ratio = ratio_list_normal_sample(1)
    uniform_discontinous_ratio = ratio_list_normal_sample(2)
    simulate_real_ratio = ratio_list_normal_sample(3)
    normal_distribution_ratio = ratio_list_normal_sample(4)

    uniform_continous_eff = cal_coverage_effience(uniform_continous_ratio)
    uniform_discontinous_eff = cal_coverage_effience(uniform_discontinous_ratio)
    simulate_real_eff =  cal_coverage_effience(simulate_real_ratio)
    normal_distribution_eff = cal_coverage_effience(normal_distribution_ratio)


    plt.scatter(uniform_continous_eff[0][0], uniform_continous_eff[0][1], color='b')
    plt.scatter(uniform_discontinous_eff[0][0], uniform_discontinous_eff[0][1], color='r')
    plt.scatter(simulate_real_eff [0][0], simulate_real_eff [0][1], color='g')
    plt.scatter(normal_distribution_eff[0][0], normal_distribution_eff[0][1], color='y')

    print("un_con_eff: converage  :  {}, coverage velocity: {}, launch:{} ".format(uniform_continous_eff[0],uniform_continous_eff[1],uniform_continous_eff[2]))
    print("un_discon_eff: converage  :  {}, coverage velocity: {}, launch:{} ".format(uniform_discontinous_eff[0],uniform_discontinous_eff[1],uniform_discontinous_eff[2]))
    print("sim_eff: converage :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff[0],simulate_real_eff[1],simulate_real_eff[2]))
    print("nor_eff: converage  :  {}, coverage velocity: {}, launch:{} ".format(normal_distribution_eff[0],normal_distribution_eff[1],normal_distribution_eff[2]))
   
    plt.plot(x,uniform_continous_ratio,label="uniform_continous_ratio")
    plt.plot(x,uniform_discontinous_ratio,label="uniform_discontinous_ratio",linestyle = "--")
    plt.plot(x,simulate_real_ratio ,label="simulate_real_ratio ",linestyle = ":")    
    plt.plot(x,normal_distribution_ratio,label="normal_distribution_ratio",linestyle = "dashed")   
    plt.xlabel("log the size of message")
    plt.ylabel("compression ratio") 

    plt.title('the compress ratio in different distribution with the size of message')
    plt.legend()   #打上标签
    plt.show()





# draw_compress_ratio_with_log_size_normal_sample()
# model_element()
# Tencoder = encode.Encoder()
# Tencoder.encodeFile(dist_txt_dict[2].format(2**i), dict_encode_dict[2].format(2**i)

def ratio_list_block_sample(dist_n,block_size = 1,x_l = 15):
    Tencoder = encode.Encoder(block_size)
    ratio_list = []
    for i in range(1,x_l):
        Tencoder.encodeFile(dist_txt_dict[dist_n].format(int(2**i)), dict_encode_dict[dist_n].format(int(2**i)))
        size_before =os.path.getsize( dist_txt_dict[dist_n].format(int(2**i)))
        size_after =os.path.getsize(dict_encode_dict[dist_n].format(int(2**i)))
        ratio = (size_after) / (size_before + 0.5 )
        ratio_list.append(ratio)
        print(dist_txt_dict[dist_n].format(2**i) , "block = {},before encode: {}".format(block_size,size_before),"byte;\n after encode: {}".format(size_after),"byte\n; compress ratio is {}".format(ratio))

    return ratio_list


def draw_compress_ratio_with_log_size_block():
    x = np.arange(1,15, 1)


    simulate_real_ratio_1 = ratio_list_block_sample(dist_n =3,block_size =1)
    simulate_real_ratio_2 = ratio_list_block_sample(dist_n =3,block_size =  32 )
    simulate_real_ratio_3 = ratio_list_block_sample(dist_n= 3,block_size =  128)
    # simulate_real_ratio_4 = ratio_list_block_sample(dist_n =3,block_size =4)
    # simulate_real_ratio_5 = ratio_list_block_sample(dist_n= 3,block_size =5)

    simulate_real_eff_1 =  cal_coverage_effience(simulate_real_ratio_1)
    simulate_real_eff_2 =  cal_coverage_effience(simulate_real_ratio_2)
    simulate_real_eff_3 =  cal_coverage_effience(simulate_real_ratio_3)
    # simulate_real_eff_4 =  cal_coverage_effience(simulate_real_ratio_4)
    # simulate_real_eff_5 =  cal_coverage_effience(simulate_real_ratio_5)

    plt.scatter(simulate_real_eff_1 [0][0], simulate_real_eff_1 [0][1], color='g')
    plt.scatter(simulate_real_eff_2 [0][0], simulate_real_eff_2 [0][1], color='r')
    plt.scatter(simulate_real_eff_3 [0][0], simulate_real_eff_3 [0][1], color='y')
    # plt.scatter(simulate_real_eff_4 [0][0], simulate_real_eff_4 [0][1], color='b')
    # plt.scatter(simulate_real_eff_5 [0][0], simulate_real_eff_5 [0][1], color='#FF1493')


    print("block = 1: converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_1[0][0],simulate_real_eff_1[1],simulate_real_eff_1[2]))
    print("block = 2:  converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_2[0][0],simulate_real_eff_2[1],simulate_real_eff_2[2]))
    print("block = 3: converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_3[0][0],simulate_real_eff_3[1],simulate_real_eff_3[2]))
    # print("block = 4:  converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_4[0][0],simulate_real_eff_4[1],simulate_real_eff_4[2]))
    # print("block = 5: converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_5[0][0],simulate_real_eff_5[1],simulate_real_eff_5[2]))


    plt.plot(x,simulate_real_ratio_1,label="block = 1")
    plt.plot(x,simulate_real_ratio_2,label="block = 2",linestyle = "--")
    plt.plot(x,simulate_real_ratio_3 ,label="block = 3 ",linestyle = ":")    
    # plt.plot(x,simulate_real_ratio_4,label="block = 4",linestyle = "dashed")   
    # plt.plot(x,simulate_real_ratio_5,label="block = 5",linestyle ="dashdot")  
    plt.xlabel("log the size of message")
    plt.ylabel("compression ratio") 

    plt.title('the compress raio in different distribution with the size of message using block sample'.format())
    plt.legend()   #打上标签
    plt.show()

# draw_compress_ratio_with_log_size_block()
# draw_compress_ratio_with_log_size_block(2)
# draw_compress_ratio_with_log_size_block(3)
# draw_compress_ratio_with_log_size_block(4)
# draw_compress_ratio_with_log_size_block(5)


def ratio_list_block_sample(block_size = 1,k_wins = 1,x_l = 10):
    dist_n = 3
    Tencoder = encode.Encoder(block_size)
    ratio_list = []
    for i in range(5,x_l):
        Tencoder.encodeFile(dist_txt_dict[dist_n].format(int(2**i)), dict_encode_dict[dist_n].format(int(2**i)))
        size_before =os.path.getsize( dist_txt_dict[dist_n].format(int(2**i)))
        size_after =os.path.getsize(dict_encode_dict[dist_n].format(int(2**i)))
        ratio = (size_after) / (size_before + 0.5 )
        ratio_list.append(ratio)
        print(dist_txt_dict[dist_n].format(2**i) , "block = {},before encode: {}".format(block_size,size_before),"byte;\n after encode: {}".format(size_after),"byte\n; compress ratio is {}".format(ratio))

    return ratio_list

# def draw_compression_ratio_k_windows(block_size):
#     x = np.arange(5, 10, 1)


#     simulate_real_ratio_1 = ratio_list_block_sample(block_size =1)
#     simulate_real_ratio_2 = ratio_list_block_sample(dist_n =3,block_size =2)
#     simulate_real_ratio_3 = ratio_list_block_sample(dist_n= 3,block_size =3)
#     simulate_real_ratio_4 = ratio_list_block_sample(dist_n =3,block_size =4)
#     simulate_real_ratio_5 = ratio_list_block_sample(dist_n= 3,block_size =5)

#     simulate_real_eff_1 =  cal_coverage_effience(simulate_real_ratio_1)
#     simulate_real_eff_2 =  cal_coverage_effience(simulate_real_ratio_2)
#     simulate_real_eff_3 =  cal_coverage_effience(simulate_real_ratio_3)
#     simulate_real_eff_4 =  cal_coverage_effience(simulate_real_ratio_4)
#     simulate_real_eff_5 =  cal_coverage_effience(simulate_real_ratio_5)

#     plt.scatter(simulate_real_eff_1 [0][0], simulate_real_eff_1 [0][1], color='g')
#     plt.scatter(simulate_real_eff_2 [0][0], simulate_real_eff_2 [0][1], color='r')
#     plt.scatter(simulate_real_eff_3 [0][0], simulate_real_eff_3 [0][1], color='y')
#     plt.scatter(simulate_real_eff_4 [0][0], simulate_real_eff_4 [0][1], color='b')
#     plt.scatter(simulate_real_eff_5 [0][0], simulate_real_eff_5 [0][1], color='#FF1493')


#     print("block = 1: converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_1[0][0],simulate_real_eff_1[1],simulate_real_eff_1[2]))
#     print("block = 2:  converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_2[0][0],simulate_real_eff_2[1],simulate_real_eff_2[2]))
#     print("block = 3: converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_3[0][0],simulate_real_eff_3[1],simulate_real_eff_3[2]))
#     print("block = 4:  converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_4[0][0],simulate_real_eff_4[1],simulate_real_eff_4[2]))
#     print("block = 5: converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(simulate_real_eff_5[0][0],simulate_real_eff_5[1],simulate_real_eff_5[2]))


#     plt.plot(x,simulate_real_ratio_1,label="block = 1")
#     plt.plot(x,simulate_real_ratio_2,label="block = 2",linestyle = "--")
#     plt.plot(x,simulate_real_ratio_3 ,label="block = 3 ",linestyle = ":")    
#     plt.plot(x,simulate_real_ratio_4,label="block = 4",linestyle = "dashed")   
#     plt.plot(x,simulate_real_ratio_5,label="block = 5",linestyle ="dashdot")  
#     plt.xlabel("log the size of message")
#     plt.ylabel("compression ratio") 

#     plt.title('the compress raio in different distribution with the size of message using block sample \n block size = {}'.format(block_size))
#     plt.legend()   #打上标签
#     plt.show()


def ratio_list_normal(x_l = 10):
    dist_n = 3
    Tencoder = encode.Encoder()
    ratio_list = []
    for i in range(5,x_l):
        Tencoder.encodeFile(dist_txt_dict[dist_n].format(int(2**i)), dict_encode_dict[dist_n].format(int(2**i)))
        size_before =os.path.getsize( dist_txt_dict[dist_n].format(int(2**i)))
        size_after =os.path.getsize(dict_encode_dict[dist_n].format(int(2**i)))
        ratio = (size_after) / (size_before + 0.5 )
        ratio_list.append(ratio)
        print(dist_txt_dict[dist_n].format(2**i) , "without buffrt before encode: {}".format(size_before),"byte;\n after encode: {}".format(size_after),"byte\n; compress ratio is {}".format(ratio))

    return ratio_list

def ratio_list_buffer(x_l = 10):
    dist_n = 3
    Tencoder = encode.Encoder(Buffer = True)
    ratio_list = []
    for i in range(5,x_l):
        Tencoder.encodeFile(dist_txt_dict[dist_n].format(int(2**i)), dict_encode_dict[dist_n].format(int(2**i)))
        size_before =os.path.getsize( dist_txt_dict[dist_n].format(int(2**i)))
        size_after =os.path.getsize(dict_encode_dict[dist_n].format(int(2**i)))
        ratio = ((size_after) + math.log(26) / math.log(2) * math.log(64) / 2**(i-4) / 64)  / (size_before + 0.5 )
        ratio_list.append(ratio)
        print(dist_txt_dict[dist_n].format(2**i) , "before encode: {}".format(size_before),"byte;\n after encode: {}".format(size_after),"byte\n; compress ratio is {}".format(ratio))

    return ratio_list



def draw_compress_ratio_with_buffer():
    x = np.arange(5,20, 1)

    normal_H_ratio = ratio_list_normal(20)
    buffer_H_ratio = ratio_list_buffer(20)

    normal_H_eff = cal_coverage_effience(normal_H_ratio)
    buffer_H_eff = cal_coverage_effience(buffer_H_ratio)

    
    plt.scatter( normal_H_eff [0][0], normal_H_eff [0][1], color='g')
    plt.scatter(buffer_H_eff  [0][0], buffer_H_eff [0][1], color='r')


    print("without buffrt: converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(normal_H_eff[0],normal_H_eff[1],normal_H_eff[2]))
    print("buffer = 64:  converage 'time' :  {}, coverage velocity: {}, launch:{} ".format(buffer_H_eff[0][0],buffer_H_eff[1],buffer_H_eff[2]))




    plt.plot(x, normal_H_ratio,label="without buffer")
    plt.plot(x,buffer_H_ratio,label="with buffer = 64",linestyle = "--")

    plt.xlabel("log the size of message")
    plt.ylabel("compression ratio") 

    plt.title('the compress raio  with the size of message using block sample'.format())
    plt.legend()   #打上标签
    plt.show()

draw_compress_ratio_with_buffer()