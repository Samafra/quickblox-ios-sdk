//
//  Delegates.h
//  QBChat
//
//  Copyright 2012 QuickBlox team. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kStopVideoChatCallStatus_OpponentDidNotAnswer @"kStopVideoChatCallStatus_OpponentDidNotAnswer"
#define kStopVideoChatCallStatus_Manually @"kStopVideoChatCallStatus_Manually"

/**
 QBChatDelegate protocol definition
 This protocol defines methods signatures for callbacks. Implement this protocol in your class and
 set [QBChat instance].delegate to your implementation instance to receive callbacks from QBChat
 */

@protocol QBChatDelegate <NSObject>
@optional

#pragma mark -
#pragma mark Base IM

/**
 didLogin fired by QBChat when connection to service established and login is successfull
 */
- (void)chatDidLogin;

/**
 didNotLogin fired when login process did not finished successfully
 */
- (void)chatDidNotLogin;

/**
 didNotSendMessage fired when message cannot be send to user
 
 @param message Message passed to sendMessage method into QBChat
 */
- (void)chatDidNotSendMessage:(QBChatMessage *)message;

/**
 didReceiveMessage fired when new message was received from QBChat
 
 @param message Message received from Chat
 */
- (void)chatDidReceiveMessage:(QBChatMessage *)message;

/**
 didFailWithError fired when connection error occurs
 
 @param error Error code from QBChatServiceError enum
 */
- (void)chatDidFailWithError:(int)error;

/**
 Called in case receiving presence
 
 @param userID User ID from which received presence
 @param type Presence type
 */
- (void)chatDidReceivePresenceOfUser:(NSUInteger)userID type:(NSString *)type;


#pragma mark -
#pragma mark Rooms

/**
 Called in case received list of available to join rooms.
 
 @rooms Array of rooms
 */
- (void)chatDidReceiveListOfRooms:(NSArray *)rooms;

/**
 Called when room received message. It will be fired each time when room received message from any user
 
 @param message Received message
 @param roomName Name of room which reeived message
 */
- (void)chatRoomDidReceiveMessage:(QBChatMessage *)message fromRoom:(NSString *)roomName;

/**
 Fired when you did enter to room
 
 @param room which you have joined
 */
- (void)chatRoomDidEnter:(QBChatRoom *)room;

/**
 Called when you didn't enter to room
 
 @param room which you haven't joined
 @param error Error
 */
- (void)chatRoomDidNotEnter:(NSString *)roomName error:(NSError *)error;

/**
 Fired when you did leave room
 
 @param Name of room which you have leaved
 */
- (void)chatRoomDidLeave:(NSString *)roomName;

/**
 Called in case changing online users  
 
 @param onlineUsers Array of online users
 @param roomName Name of room in which have changed online users
 */
- (void)chatRoomDidChangeOnlineUsers:(NSArray *)onlineUsers room:(NSString *)roomName;

/**
 Called in case receiving list of users who can join room
 
 @param users Array of users which are able to join room
 @param roomName Name of room which provides access to join
 */
- (void)chatRoomDidReceiveListOfUsers:(NSArray *)users room:(NSString *)roomName;


#pragma mark -
#pragma mark Video Chat

/**
 Called in case when opponent is calling to you
 
 @param userID ID of uopponent
 @param conferenceType Type of conference. 'QBVideoChatConferenceTypeAudioAndVideo' value only available now
 */
-(void) chatDidReceiveCallRequestFromUser:(NSUInteger)userID conferenceType:(enum QBVideoChatConferenceType)conferenceType;

/**
 Called in case when you are calling to user, but hi hasn't answered
 
 @param userID ID of opponent
 */
-(void) chatCallUserDidNotAnswer:(NSUInteger)userID;

/**
 Called in case when opponent has accepted you call
 
 @param userID ID of opponent
 */
-(void) chatCallDidAcceptByUser:(NSUInteger)userID;

/**
 Called in case when opponent has rejected you call
 
 @param userID ID of opponent
 */
-(void) chatCallDidRejectByUser:(NSUInteger)userID;

/**
 Called in case when opponent has finished call
 
 @param userID ID of opponent
 @param status Reason of finish call. There are 2 reasons: 1) Opponent did not answer - 'kStopVideoChatCallStatus_OpponentDidNotAnswer'. 2) Opponent finish call with method 'finishCall' - 'kStopVideoChatCallStatus_Manually'
 */
-(void) chatCallDidStopByUser:(NSUInteger)userID status:(NSString *)status;

/**
 Called in case when call has started
 
 @param userID ID of opponent
 */
-(void) chatCallDidStartWithUser:(NSUInteger)userID;

/**
 Set view to which will be rendered opponent's video stream
 
 @return UIImageView, to which will be rendered opponent's video stream
 */
- (UIImageView *) viewToRenderOpponentVideoStream;

/**
  Set view to which will be rendered your video stream
 
 @return UIImageView, to which will be rendered your video stream
 */
- (UIImageView *) viewToRenderOwnVideoStream;


#pragma mark -
#pragma mark Deprecated

/**
 @warning *Deprecated in QB iOS SDK 1.5:* This method will never be called now. Instead of it '- (void)chatRoomDidEnter:(QBChatRoom *)room' will be called.
 
 Fired when room was successfully created
 */
- (void)chatRoomDidCreate:(QBChatRoom*)room __attribute__((deprecated()));

@end


