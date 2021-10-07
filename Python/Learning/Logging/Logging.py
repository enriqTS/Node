import logging
import logging.config

logging.config.fileConfig('Python/Learning/Logging/logging.conf')

logger = logging.getLogger('simpleExample')
logger.debug('this is a debug message')

