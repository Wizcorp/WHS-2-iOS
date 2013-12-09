#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class MBWhsService;

@interface MBLeManager : NSObject

@property (nonatomic) CBCentralManager *centralManager;
@property (nonatomic) MBWhsService *whsService;

@property (nonatomic) CBUUID *whsServiceUUID;
@property (nonatomic) CBUUID *whsCharacteristicsUUID;
@property (nonatomic) NSMutableArray *foundPeripherals;
@property (nonatomic) NSMutableArray *connectedPeripherals;

@property (nonatomic, readonly) BOOL isBTPoweredOn;
@property (nonatomic, readonly) BOOL isSupport;

@property (nonatomic) NSData *recievedData;
@property (nonatomic) NSDate *recievedDateTime;

@property (nonatomic) NSString *debugMessage;

- (id)init;
- (void)startScan;
- (void)stopScan;
- (void)connectPeripheral:(CBPeripheral *)peripheral;
- (void)disconnectPeripheral:(CBPeripheral*)peripheral;
- (void)setNotifyAllPeripherals:(BOOL)value;
- (void)setNotify:(BOOL)value peripheral:(CBPeripheral *)peripheral;
- (void)writeValue:(CBPeripheral *)peripheral value:(NSData *)value;
- (void)disconnect;

@end