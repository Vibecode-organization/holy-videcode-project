#ifndef LOGGER_H
#define LOGGER_H

#import <Foundation/Foundation.h>

NSString *log_start(void);          // create folder + log file, install handlers
void log_write(NSString *fmt, ...); // append + fsync
void log_flush(void);

#endif
