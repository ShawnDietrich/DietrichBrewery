define(['system/widgets/CompoundWidget/CompoundWidget', 'brease/core/Types', 'text!widgets/widgetlibrary_0/RedStatusIndicator/content/widgets.css'], function (SuperClass, Types, contentCSS) {

    'use strict';

    /**
    * @class widgets.widgetlibrary_0.RedStatusIndicator
    * @extends system.widgets.CompoundWidget
    * @requires widgets.brease.Ellipse
    * @requires widgets.brease.Label
    *
    * @iatMeta category:Category
    * Compound
    * @iatMeta description:short
    * CompoundWidget
    * @iatMeta description:de
    * CompoundWidget
    * @iatMeta description:en
    * CompoundWidget
    */

    /** 
    * @cfg {Boolean} Status=false 
    * @iatStudioExposed 
    * @bindable 
    * @iatCategory Behavior 
    * Status Indicator  
    */ 
    /** 
    * @cfg {String} Label='Device Status' 
    * @iatStudioExposed 
    * @iatCategory Behavior 
    * Text Label  
    */ 

    var defaultSettings = {
            Status: false,
            Label: 'Device Status'
        },

        propertyMapping = {
            
            Status: { statOn: 'visible' }, 
            Label: { txtLabel: 'text' }
        },

        WidgetClass = SuperClass.extend(function RedStatusIndicator() {
            SuperClass.apply(this, arguments);
        }, defaultSettings),

        p = WidgetClass.prototype;
    WidgetClass.static.contentCSS = contentCSS;

    p.init = function () {
        this.initMapping(propertyMapping);
        SuperClass.prototype.init.call(this);
    };

    p.setInitialValues = function () {
        
    };
    
    
    p.setStatus = function (value) { this.settings['Status'] = value; this.setChildProps('Status', value); };
    p.setLabel = function (value) { this.settings['Label'] = value; this.setChildProps('Label', value); };
    

    return WidgetClass;

});
