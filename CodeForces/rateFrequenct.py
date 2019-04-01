import requests
import json
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns; sns.set(color_codes=True)

handle = "harshit23897"

r = requests.get("https://codeforces.com/api/user.rating?handle="+handle)
res = r.json()
#print(json.dumps(res, indent=4))

rate = []
for i in range(0,len(res["result"])):
    rate.append(res["result"][i]["oldRating"])
rate.append(res["result"][len(res["result"])-1]["newRating"])

y, x, _ =plt.hist(rate, density=True,bins=15)

idx=list(y).index(y.max())
_[idx].set_fc('orange')
sns.kdeplot(rate,shade=True,color="green")

plt.xlabel('rate')
plt.ylabel('frequency')
plt.title(handle+"'s Frequent Rate")
plt.show()
