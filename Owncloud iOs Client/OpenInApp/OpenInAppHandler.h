//
//  OpenInAppHandler.h
//  Owncloud iOs Client
//
//  Created by Pablo Carrascal on 13/12/2017.
//
//

#import <Foundation/Foundation.h>

@interface OpenInAppHandler : NSObject
@property  (readonly) NSURL *tappedLinkURL;
@property  NSURL *finalURL;
@property  UserDto *user;

/**
 * Init the handler with a url and a user.
 *
 * @param linkURL -> private link in the form https://server/f/id for example https://owncloud.com/f/13
 *
 * @param user -> UserDto of the active user.
 *
 */
-(id)initWithLink:(NSURL *)linkURL andUser:(UserDto *) user;

/**
 * Send a request to the server to obtain the redirected path if the
 * request is success, if not you'll why in form of an error.
 *
 * @param privateLink -> NSURL private link in the form
 * https://server/f/id for example https://owncloud.com/f/13
 *
 * @success
 * @return redirectedURL -> The redirected URL for the private link.
 *
 * @failure
 * @return error -> The error of the redirection request.
 */
-(void)getRedirection: (NSURL *) privateLink success:(void(^)(NSString *redirectedURL))success failure:(void(^)(NSError *error)) failure;

/**
 * Obtain the files inside a folder
 *
 * @param folderPath -> url of the folder you want the files.
 *
 * @success
 * @return items -> array with the files inside a folder.
 *
 * @failure
 * @return error -> error of this request.
 *
 */
-(void)getFilesFrom: (NSString *) folderPath success:(void(^)(NSArray *items))success failure:(void(^)(NSError *error)) failure;

/**
 * Handle the hole process from requesting the redirected link
 * to handle the process of getting all the files inside the folder
 * and managing the errors.
 *
 * @param folderPath -> url of the folder you want the files.
 *
 * @success
 * @return items -> array with the files inside a folder.
 *
 * @failure
 * @return error -> error of the hole process of requesting a private link folder.
 *
 */

-(void)handleLink: (void(^)(NSArray *items))success failure:(void(^)(NSError *error)) failure;

/**
 * Cache in database the FileDTO of the downloaded private link.
 *
 * @param downloadedFolder -> array with de FileDto of the downloaded folder.
 *
 */

-(void)cacheDownloadedFolder:(NSMutableArray *)downloadedFolder withParent:(FileDto *)parent;

@end
