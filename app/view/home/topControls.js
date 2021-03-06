/*
 * Copyright (c) 2013, Ford Motor Company All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: ·
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. · Redistributions in binary
 * form must reproduce the above copyright notice, this list of conditions and
 * the following disclaimer in the documentation and/or other materials provided
 * with the distribution. · Neither the name of the Ford Motor Company nor the
 * names of its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * @name SDL.TopControls
 *
 * @desc Component for Home top controls
 *
 * @category	view
 * @filesource	app/view/home/topControls.js
 * @version		1.0
 */

SDL.TopControls = Em.ContainerView.extend({

  elementId: 'app_top_menu_cont',

  childViews: [
      'controls'
  ],

  controls: Em.ContainerView.extend({
    elementId: 'top_controls',

    childViews: [
        'clock',
        'sdlControlStatus'
    ],

    clock: Em.View.extend({
      elementId:			'clock',
      template: Em.Handlebars.compile('<div id="time_num">12:21 86°</div>')
    }),

    sdlControlStatus: SDL.Button.extend({
      elementId:			'sdlControlStatus',

      classNameBindings: [
          'SDL.States.media.player.radio.active:active_state',
          'SDL.SDLModel.givenControlFlag:mobile',
          'SDL.FuncSwitcher.rev::is-disabled'
      ],

      target: 'SDL.SDLModel',

      action: 'resetControl',

      template: Em.Handlebars.compile(
          '<div class="icon"></div>' +
          '<div class="mask"></div>'
      )
    })
  })
});
