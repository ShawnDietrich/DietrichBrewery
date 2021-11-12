define([
    'brease/core/Class'
], function (
    SuperClass
) {

    'use strict';

    var ModuleClass = SuperClass.extend(function EditorHandles(widget) {
            SuperClass.call(this);

            this.widget = widget;
            this.oldSettings = {
                top: this.widget.settings.top,
                left: this.widget.settings.left,
                width: this.widget.settings.width,
                height: this.widget.settings.height
            };

        }, null),

        p = ModuleClass.prototype;

    p.getHandles = function () {

        var self = this;
        return {
            moveHandles: undefined, /* use default*/
            pointHandles: undefined,
            resizeHandles: [{

                start: function () {
                    _retainSettings(self);
                },

                update: function (newBox, direction) {
                    self.widget.settings.top = newBox.top;
                    self.widget.settings.left = newBox.left;
                    self.widget.settings.width = newBox.width;
                    self.widget.settings.height = newBox.height;
                    self.widget.adjustSize();
                    self.widget.adjustPosition();
                },

                finish: function () {
                    return _compareSettings(self);
                },

                handle: function () {
                    return self.widget.elem;
                }
            }]
        };
    };

    p.getSelectionDecoratables = function () {
        return [this.widget.elem];
    };

    function _retainSettings(self) {
        self.oldSettings.top = self.widget.settings.top;
        self.oldSettings.left = self.widget.settings.left;
        self.oldSettings.width = self.widget.settings.width;
        self.oldSettings.height = self.widget.settings.height;
    }

    function _compareSettings(self) {

        var returnValue = {};

        if (self.widget.settings.top !== self.oldSettings.top) {
            returnValue.top = self.widget.settings.top;
        }
        if (self.widget.settings.left !== self.oldSettings.left) {
            returnValue.left = self.widget.settings.left;
        }
        if ((self.widget.settings.width !== self.oldSettings.width) || (self.widget.settings.height !== self.oldSettings.height)) {
            returnValue.height = self.widget.settings.height;
            returnValue.width = self.widget.settings.width;
        }

        return returnValue;
    }

    return ModuleClass;

});
