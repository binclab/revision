
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

function setupApplication(relogin){
    FB.getLoginStatus(function (response) {
        if (response.status === 'connected') {
            document.getElementById('login').style.display = 'none';
            document.getElementById('application').style.display = 'flex';
            console.log('Logged In');
        } else if(relogin){
            FB.login();
            setupApplication(false);
        }
    });
}

function openHome(){
    document.location = "https://www.binclab.com";
}