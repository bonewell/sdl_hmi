/**
 * Created by amelnik on 21.05.15.
 */

/**
 * Method to send request to server
 * @param req
 * @param callback
 * @param err
 * @param data
 */
request = function(req, callback, err, data) {

  $.ajax({
    type: 'POST',
    data: JSON.stringify({
      'objectData': req,
      'data': data
    }),
    contentType: 'application/json',
    url: 'http://localhost:3000/ajax'
  }).done(callback).fail(err);
};

$('#enter').click(function() {

  request(
      'login',
        function(data) {
          //if (data === 'new user') {
          //    $('#config').removeClass('disabled');
          //    $('#test_suite').removeClass('disabled');
          //}
        },
        null,
        $('#sing_in').val()
    );
});

$('#Register').click(function() {
  request(
      'register',
        function(data) {
        }
    );
});

selectUser = function(self) {
  $('#userNameInput').val(self.name);
};

strengthCheck = function(password, marker) {

  $(marker).removeClass('label-success');
  $(marker).removeClass('label-primary');
  $(marker).removeClass('label-warning');
  $(marker).removeClass('label-danger');

  var strength = 0;
  if (password.length < 6) {
    $(marker).addClass('label-danger');
    return 'Too short';
  }
  if (password.length > 7) {strength += 1;}
  // If password contains both lower and uppercase characters, increase strength value.
  if (password.match(/([a-z].*[A-Z])|([A-Z].*[a-z])/)) strength += 1;
  // If it has numbers and characters, increase strength value.
  if (password.match(/([a-zA-Z])/) && password.match(/([0-9])/)) strength += 1;
  // If it has one special character, increase strength value.
  if (password.match(/([!,%,&,@,#,$,^,*,?,_,~])/)) strength += 1;
  // If it has two special characters, increase strength value.
  if (password.match(/(.*[!,%,&,@,#,$,^,*,?,_,~].*[!,%,&,@,#,$,^,*,?,_,~])/)) strength += 1;
  // Calculated strength value, we can return messages
  // If value is less than 2
  if (strength < 2) {
    $(marker).addClass('label-warning');
    return 'Weak';
  } else if (strength == 2) {
    $(marker).addClass('label-primary');
    return 'Good';
  } else {
    $(marker).addClass('label-success');
    return 'Strong';
  }
};

$('#password').find('input').on('input',function(data) {

  var password = $('#password').find('input').val();
  var marker = $('#password').find('.input-group-addon');
  var result = $('#password').find('span.text');

  $(result).text(strengthCheck(password, marker));

});

$('#editTestSuit').on('click', function() {
  $('#newTestSuiteForm').attr('action', '/editTestSuit');
  $('#addNewTestSuit').submit();
});

$('#uploadUpdateTest').on('click', function() {
  $('#uploadForm').submit();
});

$('.editTestSuitListItem').on('click', function() {

  $('#testSuitInput').val(this.name);
  $('#modalLabel').text(this.name);
  $('#uploadTestSuiteSelectInput').val(this.name);
  $('#testSuiteDescription').val(suitsData[$(this).attr('index')].description);
  $('#editTestSuit').removeAttr('disabled', 'disabled').removeClass('disabled');
  $('#uploadTestSuit').removeAttr('disabled', 'disabled').removeClass('disabled');

  $('#addNewTestSuit').attr('disabled', 'disabled').addClass('disabled');

  $('#fileList').html('');

  if (suitsData[$(this).attr('index')].fileNames.length) {

    var suit = suitsData[$(this).attr('index')];

    for (var file in suit.fileNames) {
      console.log(suit.fileNames[file]);
      $('#fileList').append(
          '<a href="#" class="input-group">' +
              '<span class="form-control" filename="LuxoftInterCA.crt">' + suit.fileNames[file] + '</span>' +
              '<span class="input-group-btn">' +
                  '<button class="btn btn-warning deleteFileExecute" onclick="deleteFileExecute(' +
          'this, \'' + suit.testSuite + '\', \'' + suit.fileNames[file] + '\'' +
          ')" type="button">Delete!</button>' +
              '</span>' +
          '</a>');

    }
  } else {
    $('#fileList').html('<a href="#" class="list-group-item">No files added :(</a>');
  }

});

$('#testSuitInput').on('click', function() {
  $(this).val('');
  $('#fileList').html('<a href="#" class="list-group-item">No files added :(</a>');
  $('#editTestSuit').attr('disabled', 'disabled').addClass('disabled');
  $('#uploadTestSuit').attr('disabled', 'disabled').addClass('disabled');
  $('#addNewTestSuit').removeAttr('disabled', 'disabled').removeClass('disabled');
});

deleteFileExecute = function(element, suit, fileName) {
  request(
      'deleteFile',
        function(data) {
          notiify('success', data);
          $(element).parent().parent().remove();

          var fileItemIndex = null;

          for (var i in suitsData) {
            if (suitsData[i].testSuite === suit) {
              fileItemIndex = suitsData[i].fileNames.indexOf(fileName);
              suitsData[i].fileNames.splice(fileItemIndex, 1);
              if (suitsData[i].fileNames.length === 0) {

                $('#fileList').html('<a href="#" class="list-group-item">No files added :(</a>');
              }
            }
          }
        },
        function(data) {
          notiify('warn', data.responseText);
        },
        {
          'suit': suit,
          'fileName': fileName
        }
    );
};

//config.jade prevent DropDown list automatic close
$('.testSuitDropDownList input, .testSuitDropDownList li,  testSuitDropDownList ul').click(function(e) {
  e.stopPropagation();
});

$('#saveButton').on('click', function() {
  console.log(editor.getSession().getValue());
});
