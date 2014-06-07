#pragma once


#include "zcgi.h"

class ZcGiImpFaceStyle;
class ZcGiImpEdgeStyle;
class ZcGiImpDisplayStyle;
class ZcGiImpVisualStyle;

class ZcGiFaceStyle : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiFaceStyle);

   
    enum LightingModel { 
        kInvisible, 
        kConstant,  
        kPhong,
        kGooch
    };


    enum LightingQuality {
        kNoLighting,
        kPerFaceLighting,
        kPerVertexLighting
    };


    enum FaceColorMode {
        kNoColorMode,
        kObjectColor,
        kBackgroundColor,
        kMono,
        kTint,
        kDesaturate
    };

    enum FaceModifier {
        kNoFaceModifiers    = 0,
        kOpacity            = 1,
        kSpecular           = 2
    };

                             ZcGiFaceStyle          (void);

                             ZcGiFaceStyle          (const ZcGiFaceStyle& style);

    virtual                  ~ZcGiFaceStyle         (void);
                           
    virtual void             set                    (const ZcGiFaceStyle& style);

    virtual ZcGiFaceStyle&   operator=              (const ZcGiFaceStyle& style);

   virtual bool             operator==             (const ZcGiFaceStyle& style) const;

                               
    virtual void             setLightingModel       (LightingModel lightingModel);

    virtual LightingModel    lightingModel          (void) const;

                             
    virtual void             setLightingQuality     (LightingQuality lightingQuality);

    virtual LightingQuality  lightingQuality        (void) const;

                              
    virtual void             setFaceColorMode       (FaceColorMode mode);

    virtual FaceColorMode    faceColorMode          (void) const;
                             
    virtual void             setFaceModifiers       (unsigned long nModifiers);
                              
    virtual void             setFaceModifierFlag    (FaceModifier flag, bool bEnable);

    virtual unsigned long    faceModifiers          (void) const;

    virtual bool             isFaceModifierFlagSet  (FaceModifier flag) const;
                              
    virtual void             setOpacityLevel        (double nLevel, bool bEnableModifier);

    virtual double           opacityLevel           (void) const;
                              
    virtual void             setSpecularAmount      (double nAmount, bool bEnableModifier);

    virtual double           specularAmount         (void) const;
                              
    virtual void             setMonoColor           (const ZcCmColor& color, bool bEnableMode);

    virtual const ZcCmColor& monoColor              (void) const;
    
    virtual ZcCmColor&       monoColor              (void);

private:
    ZcGiImpFaceStyle* mpZcGiImpFaceStyle;
};


class ZcGiEdgeStyle : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiEdgeStyle);

    enum  EdgeModel {
        kNoEdges,
        kIsolines,
        kFacetEdges
    };

    enum EdgeStyle {
        kNoEdgeStyle        =  0,
        kVisible            =  1,
        kSilhouette         =  2,
        kObscured           =  4,
        kIntersection       = 8
    };

    enum EdgeModifier {
        kNoEdgeModifiers    =   0,
        kOverhang           =   1,
        kJitter             =   2,
        kWidth              =   4,
        kColor              =   8,
        kHaloGap            =  16,
        kAlwaysOnTop        =  64,
         kOpacity            = 128,
    };

    enum JitterAmount {
        kJitterLow = 1,
        kJitterMedium,
        kJitterHigh,
    };

    enum Linetype {
        kSolid = 1,
        kDashed,
        kDotted,
        kShortDash,
        kMediumDash,
        kLongDash,
        kDoubleShortDash,
        kDoubleMediumDash,
        kDoubleLongDash,
        kMediumLongDash,
        kSparseDot
    };

    enum EdgeStyleApply {
        kDefault,
        kAll
	};

                                ZcGiEdgeStyle   (void);

                                ZcGiEdgeStyle   (const ZcGiEdgeStyle& style);


    virtual                     ~ZcGiEdgeStyle  (void);
                             
    virtual void                set             (const ZcGiEdgeStyle& style);

    virtual ZcGiEdgeStyle&      operator=       (const ZcGiEdgeStyle& style);

    virtual bool                operator==      (const ZcGiEdgeStyle& style) const;
                            
    virtual void                setEdgeModel            (EdgeModel model);

    virtual EdgeModel           edgeModel               (void) const;
                             
    virtual void                setEdgeStyles           (unsigned long nStyles);
                             
    virtual void                setEdgeStyleFlag        (EdgeStyle flag, bool bEnable);

    virtual unsigned long       edgeStyles              (void) const;

    virtual bool                isEdgeStyleFlagSet      (EdgeStyle flag) const;

    virtual void                setIntersectionColor    (const ZcCmColor& color);

    virtual const ZcCmColor&    intersectionColor       (void) const; 

    virtual ZcCmColor&          intersectionColor       (void); 

    virtual void                setObscuredColor        (const ZcCmColor& color);

    virtual const ZcCmColor&    obscuredColor           (void) const;

    virtual ZcCmColor&          obscuredColor           (void);

    virtual void                setObscuredLinetype     (Linetype ltype); 

    virtual Linetype            obscuredLinetype        (void) const;

    virtual void                setIntersectionLinetype     (Linetype ltype); 

    virtual Linetype            intersectionLinetype        (void) const;

    virtual void                setCreaseAngle          (double nAngle);

    virtual double              creaseAngle             (void) const;
                              
    virtual void                setEdgeModifiers        (unsigned long nModifiers);
                               
    virtual void                setEdgeModifierFlag     (EdgeModifier flag, bool bEnable);

    virtual unsigned long       edgeModifiers           (void) const;

    virtual bool                isEdgeModifierFlagSet   (EdgeModifier flag) const;
 
    virtual void                setEdgeColor            (const ZcCmColor& color, bool bEnableModifier);

    virtual const ZcCmColor&    edgeColor               (void) const;

    virtual ZcCmColor&          edgeColor               (void);

    virtual void             setOpacityLevel        (double nLevel, bool bEnableModifier);

    virtual double           opacityLevel           (void) const;


    virtual void                setEdgeWidth            (int nWidth, bool bEnableModifier);

    virtual int                 edgeWidth               (void) const;

    virtual void                setOverhangAmount       (int nAmount, bool bEnableModifier);

    virtual int                 overhangAmount          (void) const;
 
    virtual void                setJitterAmount         (JitterAmount amount, bool bEnableModifier);
  
    virtual JitterAmount        jitterAmount            (void) const; 

    virtual void                setSilhouetteColor      (const ZcCmColor& color);

    virtual const ZcCmColor&    silhouetteColor         (void) const;

    virtual ZcCmColor&          silhouetteColor         (void);

    virtual void                setSilhouetteWidth      (short nWidth);

    virtual short               silhouetteWidth         (void) const;

    virtual void                setHaloGap              (int nHaloGap, bool bEnableModifier);

    virtual int                 haloGap                 (void) const; 

    virtual void                setIsolines             (unsigned short nIsolines);

    virtual unsigned short      isolines                (void) const; 

    virtual void                setHidePrecision        (bool bHidePrecision);

    virtual bool                hidePrecision           (void) const; 

    virtual void				setEdgeStyleApply       (EdgeStyleApply apply);

    virtual EdgeStyleApply      edgeStyleApply          (void) const; 

private:
    ZcGiImpEdgeStyle* mpZcGiImpEdgeStyle;
};

class ZcGiDisplayStyle : public ZcRxObject
{
public:

    enum DisplaySettings {
        kNone                =  0,
        kBackgrounds         =  1,
        kLighting            =  2,
        kMaterials           =  4,
        kTextures            =  8,
    };

    enum ShadowType {
        kShadowsNone,
        kShadowsGroundPlane,
        kShadowsFull,
        kShadowsFullAndGround,
    };

    ZCRX_DECLARE_MEMBERS(ZcGiDisplayStyle);

                                ZcGiDisplayStyle       (void);

                                ZcGiDisplayStyle       (const ZcGiDisplayStyle& style);

    virtual                     ~ZcGiDisplayStyle      (void);

    virtual void                set                    (const ZcGiDisplayStyle& style);

    virtual ZcGiDisplayStyle&   operator=              (const ZcGiDisplayStyle& style);

    virtual bool                operator==             (const ZcGiDisplayStyle& style) const;

    virtual void                setDisplaySettings     (unsigned long nSettings);

    virtual void                setDisplaySettingsFlag (DisplaySettings flag, bool bEnable);

    virtual unsigned long       displaySettings        (void) const;

    virtual bool                isDisplaySettingsFlagSet(DisplaySettings flag) const;

    virtual void                setBrightness          (double value);

    virtual double              brightness             (void) const;

    virtual void                setShadowType          (ShadowType type);

    virtual ShadowType          shadowType             (void) const;

private:
    ZcGiImpDisplayStyle* mpZcGiImpDisplayStyle;
};

class ZcGiVisualStyle : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiVisualStyle);

    enum Type {
        kFlat,
        kFlatWithEdges,
        kGouraud,
        kGouraudWithEdges,
        k2DWireframe,
        k3DWireframe,
        kHidden,
        kBasic,
        kRealistic,
        kConceptual,
        kCustom,
        kDim,
        kBrighten,
        kThicken,
        kLinePattern,
        kFacePattern,
        kColorChange
    };

                            ZcGiVisualStyle     (void);

                            ZcGiVisualStyle     (Type type);

                            ZcGiVisualStyle     (const ZcGiVisualStyle& visualStyle);

                            ~ZcGiVisualStyle    (void);


    ZcGiVisualStyle& operator=(const ZcGiVisualStyle& visualStyle);

    bool operator==(const ZcGiVisualStyle& visualStyle) const;
	
    void                    configureForType    (Type type);

    ZcGiFaceStyle&          faceStyle    (void)       { return mFaceStyle; }

    ZcGiEdgeStyle&          edgeStyle    (void)       { return mEdgeStyle; }

    ZcGiDisplayStyle&       displayStyle (void)       { return mDisplayStyle; }

    const ZcGiFaceStyle&    faceStyle    (void) const { return mFaceStyle; }

    const ZcGiEdgeStyle&    edgeStyle    (void) const { return mEdgeStyle; }

    const ZcGiDisplayStyle& displayStyle (void) const { return mDisplayStyle; }

    void  setFaceStyle      (const ZcGiFaceStyle& style)    { mFaceStyle = style; }

    void  setEdgeStyle      (const ZcGiEdgeStyle& style)    { mEdgeStyle = style; }

    void  setDisplayStyle   (const ZcGiDisplayStyle& style) { mDisplayStyle = style; }
    
private:

    void configureForFlat();
    void configureForFlatWithEdges();
    void configureForGouraud();
    void configureForGouraudWithEdges();
    void configureForBasic();
    void configureFor2DWireframe();
    void configureFor3DWireframe();
    void configureForHidden();
    void configureForRealistic();
    void configureForConceptual();
    void configureForDim();
    void configureForBrighten();
    void configureForThicken();
    void configureForLinePattern();
    void configureForFacePattern();
    void configureForColorChange();

    ZcGiFaceStyle       mFaceStyle;
    ZcGiEdgeStyle       mEdgeStyle;
    ZcGiDisplayStyle    mDisplayStyle;
};


class ZcGiVisualStyleTraits : public ZcGiDrawableTraits
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGiVisualStyleTraits);

    virtual void                   setZcGiVisualStyle   (const ZcGiVisualStyle& visualStyle) = 0;

    virtual const ZcGiVisualStyle& zcgiVisualStyle      (void) const = 0;
};
