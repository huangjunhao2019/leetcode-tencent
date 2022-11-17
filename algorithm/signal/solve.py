import json
import numpy
import matplotlib.pyplot as plt
mac2List=dict()
def drawPic(mac2List):
    for key,valList in mac2List.items():
        newValList=numpy.array(valList)
        timeStampList=list(newValList[:,0])
        signalList=list(newValList[:,1])
        plt.plot(timeStampList,signalList)
        plt.savefig("./oldPic/"+key+".jpg")
        plt.close()
with open("becon_list.json","r",encoding="utf8") as fp:
    json_data=json.load(fp)
    for ele in json_data:
        if ele["name"]+","+ele["macAddress"] in mac2List:
            mac2List[ele["name"]+","+ele["macAddress"]].append([ele["timeStamp"],ele["signalStrength"]])
        else:
            mac2List[ele["name"]+","+ele["macAddress"]]=[[ele["timeStamp"],ele["signalStrength"]]]
drawPic(mac2List)
n = 100
for key,valList in mac2List.items():
    newValList=numpy.array(valList)
    timeStampList=list(newValList[:,0])
    signalList=list(newValList[:,1])
    newTimeList=[]
    newSignaleList=[]
    for i in range(n//2,len(valList)-n//2):
        sum=0
        for j in range(i-n//2,i+n//2):
            sum+=signalList[j]
        newTimeList.append(timeStampList[i])
        newSignaleList.append(sum/n)
    plt.plot(newTimeList,newSignaleList)
    plt.savefig("./newPic/"+key+".jpg")
    plt.close()
