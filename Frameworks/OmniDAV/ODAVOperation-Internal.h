// Copyright 2008-2013 Omni Development, Inc. All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

#import <OmniDAV/ODAVOperation.h>

@interface ODAVOperation ()

- initWithRequest:(NSURLRequest *)request
#if ODAV_NSURLSESSION
             task:(NSURLSessionDataTask *)task
#else
       connection:(NSURLConnection *)connection
#endif
    ;

#if ODAV_NSURLSESSION
@property(nonatomic,readonly) NSURLSessionTask *task;
#else
@property(nonatomic,readonly) NSURLConnection *connection;
#endif

//@property(nonatomic,copy) void (^validateCertificateForChallenge)(ODAVOperation *op, NSURLAuthenticationChallenge *challenge);
//@property(nonatomic,copy) NSURLCredential *(^findCredentialsForChallenge)(ODAVOperation *op, NSURLAuthenticationChallenge *challenge);

- (void)_credentialsNotFoundForChallenge:(NSURLAuthenticationChallenge *)challenge;
- (void)_didCompleteWithError:(NSError *)error;
- (void)_didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
- (void)_didReceiveResponse:(NSURLResponse *)response;
- (void)_didReceiveData:(NSData *)data;
- (NSURLRequest *)_willSendRequest:(NSURLRequest *)request redirectResponse:(NSURLResponse *)redirectResponse;

@end
