from PIL import Image


def combine_image(img, n):
    """
    Pastes together img n times
    """
    (w, h) = img.size
    new_img = Image.new('RGB', (w*(n + 1), h))

    for i in xrange(0, (n + 1)):
        new_img.paste(img, (w*i, 0))

    new_img.show()


if __name__ == "__main__":

    img_name = raw_input("What is the image name (located in imgs)\n>")
    n = raw_input("How many times do you want it to combine?\n>")
    n = int(n)

    full_image_name = "../imgs/" + img_name

    # open image
    im = Image.open(full_image_name)

    combine_image(im, n)
