"""
Purpose: 1. Download images from a list of urls save in urllist.txt and save
         them in ./images folder.
         2. Make a zip file named imageArchive.zip with those images.
"""
from __future__ import print_function

import requests
import os
from zipfile import ZipFile

def get_filename(url):
	"""
	Extracts filename from the url
	return the last path
	"""
	return url.split('/')[-1]

try:
	os.mkdir('images')
except OSError:
	pass

with open('urllist.txt', 'r') as listfile, ZipFile('imageArchive.zip', 'a') as myzip:
	for line in listfile:
		image_url = line.strip('\n')
		filename = get_filename(image_url)
		print("Downloading", filename, "...")
		img = requests.get(image_url, stream=True)
		if img.status_code == 200:
			with open('images/' + filename, 'wb') as f:
				for chunk in img:
					f.write(chunk)

		myzip.write(os.path.join('./images', filename), filename)
