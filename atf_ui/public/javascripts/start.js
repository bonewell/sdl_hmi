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

    $('#userName').find('span.text').addClass('hidden');
    $('#userName').find('.glyphicon-refresh').removeClass('hidden');
    $('#userName').find('.glyphicon-refresh').addClass('rotate360');
    request(
        'isUserExist',
        function(data){
            notiify("success", "User name available");
            $('#userName').find('.glyphicon-refresh').addClass('hidden');
            $('#userName').find('.glyphicon-refresh').removeClass('rotate360');
            $('#userName').find('span.text').removeClass('hidden');
            $('#userName').find('span.text').css("color", "green");
            $('#userName').find('span.text').text("good");
        },
        function(data){

            notiify("warn", data.responseText);
            $('#userName').find('.glyphicon-refresh').addClass('hidden');
            $('#userName').find('.glyphicon-refresh').removeClass('rotate360');
            $('#userName').find('span.text').removeClass('hidden');
            $('#userName').find('span.text').css("color", "red");
            $('#userName').find('span.text').text("error");
        },
        $("#userName").find("input").val()
    );
});