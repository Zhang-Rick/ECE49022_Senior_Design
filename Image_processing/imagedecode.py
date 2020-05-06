from PIL import Image

im = Image.open('image1.jpg') # read through file

i = 0
j = 0
total = 0
ar1 = []
image123 = im.load() # transfer to image123 PixelAccess
print('input result',image123[0,0]) # this should be the input result
# convert colorful diagram to grey-scale
while i < 128:
    j = 0
    while j < 128:

        rgb = image123[int(j*(im.size[0]/128)),int(i*(im.size[1]/128))]
        y = (0.3 * rgb[0]) + (0.59 * rgb[1]) + (0.11 * rgb[2])
        total += y
        ar1.append(y)
        j += 1
    i += 1

# convert to black and white version
i = 0
f = open('output123.txt', 'w+')
yarray = []

mean = total/(128*128)
i = 0
while i < len(ar1):
    if ar1[i] >= mean:
        x = 1
    else:
        x = 0
    if (i % 128)!= 0:
        f.write(str(x))
        f.write(',')
    else:
        f.write('\n')
        f.write(str(x))
        f.write(',')
    i += 1
