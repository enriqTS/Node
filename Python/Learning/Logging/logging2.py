#Ajuda em troubleshoot
import logging
import traceback

try:
    a = [1, 2, 3]
    val = a[4]
except IndexError as e:
    logging.error(e, exc_info=True)

try:
    a = [1, 2, 3]
    val = a[4]
except IndexError as e:
    logging.error("The error is %s", traceback.format_exc())