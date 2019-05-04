import pandas as pd
from bs4 import BeautifulSoup
import requests
url = 'http://taas.koroad.or.kr/data/rest/frequentzone/child?authKey=Wq1O1UCzy2xNgBT6acbwJ8xHCIbnoaZlbgfh92mNXPE2UOSCH%2F1ZMRX694yzMIhN&searchYearCd=2017027&sido=11&guGun=740'
req = requests.get(url)
html = req.text
soup = BeautifulSoup(html,'html.parser')
lo_crdlist = []
la_crdlist = []
la_crd = soup.find_all('la_crd')
lo_crd = soup.find_all('lo_crd')
for code in la_crd:
	la_crdlist.append(code.text)
	
for code in lo_crd:
	lo_crdlist.append(code.text)
