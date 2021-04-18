# Sarah Tavana
# sat0227
# CSCE 3444.001

# This program uses BeautifulSoup to pull headlines from the
# business, style, and entertainment sections of the CNN website.

# For instructions on how to install the necessary libraries,
# please see README.txt

from bs4 import BeautifulSoup
import requests
import csv

#--------- STORE URLS FOR EACH PAGE ------------
business_url = 'https://www.cnn.com/business'
entertainment_url = 'https://www.cnn.com/entertainment'
style_url = 'https://www.cnn.com/style'

#------- PULL AND STORE HTML OF EACH PAGE ------
business_response = requests.get(business_url)
entertainment_response = requests.get(entertainment_url)
style_response = requests.get(style_url)

business_soup = BeautifulSoup(business_response.content, 'html5lib')
entertainment_soup = BeautifulSoup(entertainment_response.content, 'html5lib')
style_soup = BeautifulSoup(style_response.content, 'html5lib')

# Create lists to store headlines.
business_headlines=[]
entertainment_headlines=[]
style_headlines=[]



#-------------FIND BUSINESS HEADLINES--------------------------

# Isolate part of the page that contains the headlines
business_table = business_soup.find(id="business-zone-1")

for row in business_table.findAll('h3', class_="cd__headline"):
    business_headlines.append(row.find(class_= 'cd__headline-text vid-left-enabled').get_text())

#--------------FIND ENTERTAINMENT HEADLINES-----------------

# Only the first 4 zones are entertainment artciles, so the program
# parses each one.

#               ZONE 1
entertainment_table_temp = entertainment_soup.find(id="entertainment-zone-1") #find headlines in zone 1
for row in entertainment_table_temp.findAll('h3', class_="cd__headline"):
    entertainment_headlines.append(row.find(class_= 'cd__headline-text vid-left-enabled').get_text())

#               ZONE 2
entertainment_table_temp = entertainment_soup.find(id="entertainment-zone-2") #find headlines in zone 2
for row in entertainment_table_temp.findAll('h3', class_="cd__headline"):
    entertainment_headlines.append(row.find(class_= 'cd__headline-text vid-left-enabled').get_text())

#               ZONE 3
entertainment_table_temp = entertainment_soup.find(id="entertainment-zone-3") #find headlines in zone 3
for row in entertainment_table_temp.findAll('h3', class_="cd__headline"):
    entertainment_headlines.append(row.find(class_= 'cd__headline-text vid-left-enabled').get_text())

#               ZONE 4
entertainment_table_temp = entertainment_soup.find(id="entertainment-zone-4") #find headlines in zone 3
for row in entertainment_table_temp.findAll('h3', class_="cd__headline"):
    entertainment_headlines.append(row.find(class_= 'cd__headline-text vid-left-enabled').get_text())

#------------- FIND STYLE HEADLINES---------------------------

# Isolate part of the page that contains the headlines
style_table = style_soup.find('div', attrs = {'class':'Homepage__component'})

#                       CARDSLIDE
for row in style_table.findAll('div', class_="EditorsChoice__carousel"):
    style_headlines.append(row.find('h1', attrs = {'class':'CardSlide__title'}).get_text())

#                         ZONE 1
#                    rest of headlines
for row in style_table.findAll('div', class_="CardBasic__details"):
    style_headlines.append(row.find('a', attrs = {'class':'CardBasic__title'}).get_text())

#-------------PRINT HEADLINES TO CSV-------------------
allHeadlines = zip(business_headlines, entertainment_headlines, style_headlines) #make list of lists so it prints neatly

filename = 'headlines.csv'
with open(filename, 'w', newline='') as f:
    w = csv.writer(f)
    w.writerow(['Business', 'Entertainment', 'Style'])
    for headline in allHeadlines:
        w.writerow(headline)
