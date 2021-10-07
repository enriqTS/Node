import logging
import time
from logging.handlers import TimedRotatingFileHandler

logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)

# roll over after 2KB, and keep backup logs app.log.1, app.log.2, etc
handler = TimedRotatingFileHandler('timed_test.log', when='s', interval=5 , backupCount=5)
logger.addHandler(handler)

for _ in range(6):
    logger.info('Hello World')
    time.sleep(5)