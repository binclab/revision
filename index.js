
function setupFacebook() {
    window.fbAsyncInit = function () {
        FB.init({
            appId: '310224639988557',
            cookie: true,
            xfbml: true,
            version: 'v15'
        });

        FB.AppEvents.logPageView();
    };
    FB.getLoginStatus(function (response) {
        if (response.status === 'connected') {
            console.log('Logged In');
        } else {
            FB.login();
        }
    });
}