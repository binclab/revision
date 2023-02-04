
function setupFacebook() {
    FB.init({
        appId: '310224639988557',
        cookie: true,
        xfbml: true,
        version: 'v15.0'
    });

    FB.AppEvents.logPageView();
    setupApplication(true);
}

function setupApplication(relogin) {
    FB.getLoginStatus(function (response) {
        if (response.status === 'connected') {
            document.getElementById('login').style.display = 'none';
            document.getElementById('application').style.display = 'flex';
            FB.api('/me', function (response) {
                document.getElementById('userName').innerHTML = response.name.split(' ')[0];
            });
            FB.api('/me/picture?redirect=0&width=100&height=100', function(response) {
                document.getElementById("userPicture").src = response.data.url;
            });
        } else if (relogin) {
            FB.login();
            document.location = "https://www.binclab.com/revision";
        }
    });
}

function openHome() {
    document.location = "https://www.binclab.com";
}

function logout(){
    if(window.confirm('This action will log you out from facebook as well. Proceed?')){
        FB.logout();
        document.getElementById('application').style.display = 'none';
        document.getElementById('login').style.display = 'flex';
    }
}