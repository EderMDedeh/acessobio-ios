//
// CenterModelCrop.h
//
// This file was automatically generated and should not be edited.
//

#import <Foundation/Foundation.h>
#import <CoreML/CoreML.h>
#include <stdint.h>
#include <os/log.h>

NS_ASSUME_NONNULL_BEGIN


/// Model Prediction Input Type
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0)) API_UNAVAILABLE(watchos)  __attribute__((visibility("hidden")))
@interface CenterModelCropInput : NSObject<MLFeatureProvider>

/// Input image to be classified as color (kCVPixelFormatType_32BGRA) image buffer, 299 pixels wide by 299 pixels high
@property (readwrite, nonatomic) CVPixelBufferRef image;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithImage:(CVPixelBufferRef)image NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithImageFromCGImage:(CGImageRef)image error:(NSError * _Nullable __autoreleasing * _Nullable)error API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0)) __attribute__((visibility("hidden")));

- (nullable instancetype)initWithImageAtURL:(NSURL *)imageURL error:(NSError * _Nullable __autoreleasing * _Nullable)error API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0)) __attribute__((visibility("hidden")));

-(BOOL)setImageWithCGImage:(CGImageRef)image error:(NSError * _Nullable __autoreleasing * _Nullable)error  API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0)) __attribute__((visibility("hidden")));
-(BOOL)setImageWithURL:(NSURL *)imageURL error:(NSError * _Nullable __autoreleasing * _Nullable)error  API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0)) __attribute__((visibility("hidden")));
@end


/// Model Prediction Output Type
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0)) API_UNAVAILABLE(watchos)  __attribute__((visibility("hidden")))
@interface CenterModelCropOutput : NSObject<MLFeatureProvider>

/// Probability of each category as dictionary of strings to doubles
@property (readwrite, nonatomic, strong) NSDictionary<NSString *, NSNumber *> * classLabelProbs;

/// Most likely image category as string value
@property (readwrite, nonatomic, strong) NSString * classLabel;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithClassLabelProbs:(NSDictionary<NSString *, NSNumber *> *)classLabelProbs classLabel:(NSString *)classLabel NS_DESIGNATED_INITIALIZER;

@end


/// Class for model loading and prediction
API_AVAILABLE(macos(10.13), ios(11.0), tvos(11.0)) API_UNAVAILABLE(watchos)  __attribute__((visibility("hidden")))
@interface CenterModelCrop : NSObject
@property (readonly, nonatomic, nullable) MLModel * model;

/**
    URL of the underlying .mlmodelc directory.
*/
+ (nullable NSURL *)URLOfModelInThisBundle;

/**
    Initialize CenterModelCrop instance from an existing MLModel object.

    Usually the application does not use this initializer unless it makes a subclass of CenterModelCrop.
    Such application may want to use `-[MLModel initWithContentsOfURL:configuration:error:]` and `+URLOfModelInThisBundle` to create a MLModel object to pass-in.
*/
- (instancetype)initWithMLModel:(MLModel *)model NS_DESIGNATED_INITIALIZER;

/**
    Initialize CenterModelCrop instance with the model in this bundle.
*/
- (nullable instancetype)init;

/**
    Initialize CenterModelCrop instance with the model in this bundle.

    @param configuration The model configuration object
    @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
*/
- (nullable instancetype)initWithConfiguration:(MLModelConfiguration *)configuration error:(NSError * _Nullable __autoreleasing * _Nullable)error API_AVAILABLE(macos(10.14), ios(12.0), watchos(5.0), tvos(12.0)) __attribute__((visibility("hidden")));

/**
    Initialize CenterModelCrop instance from the model URL.

    @param modelURL URL to the .mlmodelc directory for CenterModelCrop.
    @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
*/
- (nullable instancetype)initWithContentsOfURL:(NSURL *)modelURL error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
    Initialize CenterModelCrop instance from the model URL.

    @param modelURL URL to the .mlmodelc directory for CenterModelCrop.
    @param configuration The model configuration object
    @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
*/
- (nullable instancetype)initWithContentsOfURL:(NSURL *)modelURL configuration:(MLModelConfiguration *)configuration error:(NSError * _Nullable __autoreleasing * _Nullable)error API_AVAILABLE(macos(10.14), ios(12.0), watchos(5.0), tvos(12.0)) __attribute__((visibility("hidden")));

/**
    Construct CenterModelCrop instance asynchronously with configuration.
    Model loading may take time when the model content is not immediately available (e.g. encrypted model). Use this factory method especially when the caller is on the main thread.

    @param configuration The model configuration
    @param handler When the model load completes successfully or unsuccessfully, the completion handler is invoked with a valid CenterModelCrop instance or NSError object.
*/
+ (void)loadWithConfiguration:(MLModelConfiguration *)configuration completionHandler:(void (^)(CenterModelCrop * _Nullable model, NSError * _Nullable error))handler API_AVAILABLE(macos(11.0), ios(14.0), watchos(7.0), tvos(14.0)) __attribute__((visibility("hidden")));

/**
    Construct CenterModelCrop instance asynchronously with URL of .mlmodelc directory and optional configuration.

    Model loading may take time when the model content is not immediately available (e.g. encrypted model). Use this factory method especially when the caller is on the main thread.

    @param modelURL The model URL.
    @param configuration The model configuration
    @param handler When the model load completes successfully or unsuccessfully, the completion handler is invoked with a valid CenterModelCrop instance or NSError object.
*/
+ (void)loadContentsOfURL:(NSURL *)modelURL configuration:(MLModelConfiguration *)configuration completionHandler:(void (^)(CenterModelCrop * _Nullable model, NSError * _Nullable error))handler API_AVAILABLE(macos(11.0), ios(14.0), watchos(7.0), tvos(14.0)) __attribute__((visibility("hidden")));

/**
    Make a prediction using the standard interface
    @param input an instance of CenterModelCropInput to predict from
    @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
    @return the prediction as CenterModelCropOutput
*/
- (nullable CenterModelCropOutput *)predictionFromFeatures:(CenterModelCropInput *)input error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
    Make a prediction using the standard interface
    @param input an instance of CenterModelCropInput to predict from
    @param options prediction options
    @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
    @return the prediction as CenterModelCropOutput
*/
- (nullable CenterModelCropOutput *)predictionFromFeatures:(CenterModelCropInput *)input options:(MLPredictionOptions *)options error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
    Make a prediction using the convenience interface
    @param image Input image to be classified as color (kCVPixelFormatType_32BGRA) image buffer, 299 pixels wide by 299 pixels high:
    @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
    @return the prediction as CenterModelCropOutput
*/
- (nullable CenterModelCropOutput *)predictionFromImage:(CVPixelBufferRef)image error:(NSError * _Nullable __autoreleasing * _Nullable)error;

/**
    Batch prediction
    @param inputArray array of CenterModelCropInput instances to obtain predictions from
    @param options prediction options
    @param error If an error occurs, upon return contains an NSError object that describes the problem. If you are not interested in possible errors, pass in NULL.
    @return the predictions as NSArray<CenterModelCropOutput *>
*/
- (nullable NSArray<CenterModelCropOutput *> *)predictionsFromInputs:(NSArray<CenterModelCropInput*> *)inputArray options:(MLPredictionOptions *)options error:(NSError * _Nullable __autoreleasing * _Nullable)error API_AVAILABLE(macos(10.14), ios(12.0), watchos(5.0), tvos(12.0)) __attribute__((visibility("hidden")));
@end

NS_ASSUME_NONNULL_END
