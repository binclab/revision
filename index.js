
function setupFacebook() {
    FB.init({
        appId: '310224639988557',
        cookie: true,
        xfbml: true,
        version: 'v15.0'
    });

    FB.AppEvents.logPageView();
    FB.getLoginStatus(function (response) {
        if (response.status === 'connected') {
            console.log('Logged In');
        } else {
            FB.login();
        }
    });
}