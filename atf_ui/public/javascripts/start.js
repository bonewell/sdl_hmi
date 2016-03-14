/**
 * Created by amelnik on 21.05.15.
 */

/**
 * Method to send request to server
 * @param req - request method
 * @param callback
 */
request = function(req, callback, err, data) {

    $.ajax({
        type: 'POST',
        data: JSON.stringify({
            "objectData": req,
            "data": data
        }),
        contentType: 'application/json',
        url: 'http://localhost:3000/ajax'
    }).done(callback).fail(err);
};

notiify = function(type, message) {

    var notification = document.createElement('div');

    $(notification).addClass("alert");
    $(notification).addClass("notify");

    switch (type) {
        case "err": {
            $(notification).addClass("alert-danger");
            break;
        }
        case "warn": {
            $(notification).addClass("alert-warning");
            break;
        }
        case "success": {
            $(notification).addClass("alert-success");
            break;
        }
        case "info": {
            $(notification).addClass("alert-info");
            break;
        }
        default: {
            break;
        }
    }

    $(notification).text(message);

    $("#notify").append(notification);

    $(notification).fadeIn(100);

    setTimeout(function(){
        $(notification).fadeOut(3000); // Fade effect hiding during 3 seconds
        setTimeout(function(){$(notification).remove();}, 3100);
    },
    2000); //Notification appear time

};

$('#enter').click(function(){

    request(
        'login',
        function(data){
            if (data === 'new user') {
                $('#config').removeClass('disabled');
                $('#test_suite').removeClass('disabled');
            }
        },
        null,
        $('#sing_in').val()
    );
});

$('#Register').click(function(){
    request(
        'register',
        function(data){
        }
    );
});

selectUser = function(self){
    $("#userNameInput").val(self.name);
};

$('#userName').find("input").focusout(function(){

    var text = $('#userName').find('span.text');
    var icon = $('#userName').find('.glyphicon-refresh');

    $(text).addClass('hidden');
    $(icon).removeClass('hidden');
    $(icon).addClass('rotate360');
    request(
        'isUserExist',
        function(data){
            notiify("success", "User name available");
            $(icon).addClass('hidden');
            $(icon).removeClass('rotate360');
            $(text).removeClass('hidden');
            $(text).css("color", "green");
            $(text).text("good");
        },
        function(data){

            notiify("warn", data.responseText);
            $(icon).addClass('hidden');
            $(icon).removeClass('rotate360');
            $(text).removeClass('hidden');
            $(text).css("color", "red");
            $(text).text("error");
        },
        $("#userName").find("input").val()
    );
});

strengthCheck = function(password, marker){


    $(marker).removeClass('label-success');
    $(marker).removeClass('label-primary');
    $(marker).removeClass('label-warning');
    $(marker).removeClass('label-danger');

    var strength = 0;
    if (password.length < 6) {
        $(marker).addClass('label-danger');
        return 'Too short';
    }
    if (password.length > 7) strength += 1;
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
        return 'Weak'
    } else if (strength == 2) {
        $(marker).addClass('label-primary');
        return 'Good'
    } else {
        $(marker).addClass('label-success');
        return 'Strong'
    }
};


$('#password').find("input").on('input',function(data){

    var password = $('#password').find("input").val();
    var marker = $('#password').find('.input-group-addon');
    var result = $('#password').find("span.text");

    $(result).text(strengthCheck(password, marker));

});