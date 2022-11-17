import json
with open("./testJson.json","r",encoding="utf8") as fp:
    json_data=json.load(fp)
    for ele in json_data:
        print(ele["id"])