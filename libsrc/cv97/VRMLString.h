/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	VRMLString.h
*
******************************************************************/

#ifndef _CV97_VRMLSTRING_H_
#define _CV97_VRMLSTRING_H_

#define rootNodeString						"Root"
#define defNodeString						"DEF"

#define appearanceNodeString				"Appearance"
#define viewpointNodeString					"Viewpoint"
#define transformNodeString					"Transform"
#define textureCoordinateNodeString			"TextureCoordinate"
#define spotLightNodeString					"SpotLight"
#define shapeNodeString						"Shape"
#define pointLightNodeString				"PointLight"
#define normalNodeString					"Normal"
#define materialNodeString					"Material"
#define indexedFaceSetNodeString			"IndexedFaceSet"
#define groupNodeString						"Group"
#define billboardNodeString					"Billboard"
#define collisionNodeString					"Collision"
#define lodNodeString						"LOD"
#define switchNodeString					"Switch"
#define inlineNodeString					"Inline"
#define directionalLightNodeString			"DirectionalLight"
#define coordinateNodeString				"Coordinate"
#define colorNodeString						"Color"
#define worldInfoNodeString					"WorldInfo"
#define timeSensorNodeString				"TimeSensor"
#define scalarInterpolatorNodeString		"ScalarInterpolator"
#define positionInterpolatorNodeString		"PositionInterpolator"
#define coordinateInterpolatorNodeString	"CoordinateInterpolator"
#define orientationInterpolatorNodeString	"OrientationInterpolator"
#define normalInterpolatorNodeString		"NormalInterpolator"
#define colorInterpolatorNodeString			"ColorInterpolator"
#define scriptNodeString					"Script"
#define cylinderSensorNodeString			"CylinderSensor"
#define cylinderNodeString					"Cylinder"
#define anchorNodeString					"Anchor"
#define audioClipNodeString					"AudioClip"
#define backgroundNodeString				"Background"
#define boxNodeString						"Box"
#define coneNodeString						"Cone"
#define elevationGridNodeString				"ElevationGrid"
#define extrusionNodeString					"Extrusion"
#define fogNodeString						"Fog"
#define fontStyleNodeString					"FontStyle"
#define imageTextureNodeString				"ImageTexture"
#define indexedLineSetNodeString			"IndexedLineSet"
#define movieTextureNodeString				"MovieTexture"
#define navigationInfoNodeString			"NavigationInfo"
#define pixelTextureNodeString				"PixelTexture"
#define pointSetNodeString					"PointSet"
#define soundNodeString						"Sound"
#define sphereNodeString					"Sphere"
#define textNodeString						"Text"
#define planeSensorNodeString				"PlaneSensor"
#define proximitySensorNodeString			"ProximitySensor"
#define sphereSensorNodeString				"SphereSensor"
#define touchSensorNodeString				"TouchSensor"
#define visibilitySensorNodeString			"VisibilitySensor"
#define textureTransformNodeString			"TextureTransform"

#define	ambientIntensityFieldString	"ambientIntensity"
#define	attenuationFieldString		"attenuation"
#define	autoOffsetFieldString		"autoOffset"
#define	avatarSizeFieldString		"avatarSize"
#define	axisOfRotationFieldString	"axisOfRotation"
#define	backUrlFieldString			"backUrl"
#define	beamWidthFieldString		"beamWidth"
#define	beginCapFieldString			"beginCap"
#define	bindTimeFieldString			"bindTime"
#define	bottomFieldString			"bottom"
#define	bottomRadiusFieldString		"bottomRadius"
#define	bottomUrlFieldString		"bottomUrl"
#define	ccwFieldString				"ccw"
#define	centerFieldString			"center"
#define	collideFieldString			"collide"
#define	collideTimeFieldString		"collideTime"
#define	colorFieldString			"color"
#define	colorIndexFieldString		"colorIndex"
#define	colorPerVertexFieldString	"colorPerVertex"
#define	convexFieldString			"convex"
#define	coordIndexFieldString		"coordIndex"
#define	creaseAngleFieldString		"creaseAngle"
#define	crossSectionFieldString		"crossSection"
#define	cutOffAngleFieldString		"cutOffAngle"
#define	cycleIntervalFieldString	"cycleInterval"
#define	cycleTimeFieldString		"cycleTime"
#define	descriptionFieldString		"description"
#define	diffuseColorFieldString		"diffuseColor"
#define	directionFieldString		"direction"
#define	directOutputFieldString		"directOutput"
#define	diskAngleFieldString		"diskAngle"
#define	durationFieldString			"duration"
#define	emissiveColorFieldString	"emissiveColor"
#define	enabledFieldString			"enabled"
#define	endCapFieldString			"endCap"
#define	enterTimeFieldString		"enterTime"
#define	exitTimeFieldString			"exitTime"
#define	familyFieldString			"family"
#define	fieldOfViewFieldString		"fieldOfView"
#define	fogTypeFieldString			"fogType"
#define	fractionFieldString			"fraction"
#define	frontUrlFieldString			"frontUrl"
#define	groundAngleFieldString		"groundAngle"
#define	groundColorFieldString		"groundColor"
#define	headlightFieldString		"headlight"
#define	heightFieldString			"height"
#define	heightFieldString			"height"
#define	hitNormalFieldString		"hitNormal"
#define	hitPointFieldString			"hitPoint"
#define	hitTexCoordFieldString		"hitTexCoord"
#define	horizontalFieldString		"horizontal"
#define	imageFieldString			"image"
#define	infoFieldString				"info"
#define	inRegionPrivateFieldString	"inRegion"
#define	intensityFieldString		"intensity"
#define	isActiveFieldString			"isActive"
#define	isBoundFieldString			"isBound"
#define	isOverFieldString			"isOver"
#define	jumpFieldString				"jump"
#define	justifyFieldString			"justify"
#define	keyFieldString				"key"
#define keyValueFieldString			"keyValue"
#define	languageFieldString			"language"
#define	leftToRightFieldString		"leftToRight"
#define	leftUrlFieldString			"leftUrl"
#define	lengthFieldString			"length"
#define	locationFieldString			"location"
#define	loopFieldString				"loop"
#define	maxAngleFieldString			"maxAngle"
#define	maxBackFieldString			"maxBack"
#define	maxExtentFieldString		"maxExtent"
#define	maxFrontFieldString			"maxFront"
#define	maxPositionFieldString		"maxPosition"
#define	minAngleFieldString			"minAngle"
#define	minBackFieldString			"minBack"
#define	minFrontFieldString			"minFront"
#define	minPositionFieldString		"minPosition"
#define	mustEvaluateFieldString		"mustEvaluate"
#define	normalIndexFieldString		"normalIndex"
#define	normalPerVertexFieldString	"normalPerVertex"
#define	offsetFieldString			"offset"
#define	onFieldString				"on"
#define	orientationFieldString		"orientation"
#define	parameterFieldString		"parameter"
#define	pitchFieldString			"pitch"
#define	pointFieldString			"point"
#define	positionFieldString			"position"
#define	priorityFieldString			"priority"
#define	radiusFieldString			"radius"
#define	rangeFieldString			"range"
#define	repeatSFieldString			"repeatS"
#define	repeatTFieldString			"repeatT"
#define	rightUrlFieldString			"rightUrl"
#define	rotationFieldString			"rotation"
#define	scaleFieldString			"scale"
#define	scaleOrientationFieldString	"scaleOrientation"
#define	setBindFieldString			"set_bind"
#define	shininessFieldString		"shininess"
#define	sideFieldString				"side"
#define	sizeFieldString				"size"
#define	skyAngleFieldString			"skyAngle"
#define	skyColorFieldString			"skyColor"
#define	solidFieldString			"solid"
#define	spacingFieldString			"spacing"
#define	spatializeFieldString		"spatialize"
#define	specularColorFieldString	"specularColor"
#define	speedFieldString			"speed"
#define	speedTimeFieldString		"speedTime"
#define	spineFieldString			"spine"
#define	startTimeFieldString		"startTime"
#define	stopTimeFieldString			"stopTime"
#define	stringFieldString			"string"
#define	styleFieldString			"style"
#define	texCoordIndexFieldString	"texCoordIndex"
#define	timeFieldString				"time"
#define	titleFieldString			"title"
#define	topFieldString				"top"
#define	topToBottomFieldString		"topToBottom"
#define	topUrlFieldString			"topUrl"
#define	touchTimeFieldString		"touchTime"
#define	trackPointFieldString		"trackPoint"
#define	translationFieldString		"translation"
#define	transparencyFieldString		"transparency"
#define	typeFieldString				"type"
#define	urlFieldString				"url"
#define	valueFieldString			"value"
#define	vectorFieldString			"vector"
#define	visibilityLimitFieldString	"visibilityLimit"
#define	visibilityRangeFieldString	"visibilityRange"
#define	whichChoiceFieldString		"whichChoice"
#define	xDimensionFieldString		"xDimension"
#define	xSpacingFieldString			"xSpacing"
#define	zDimensionFieldString		"zDimension"
#define	zSpacingFieldString			"zSpacing"

#endif