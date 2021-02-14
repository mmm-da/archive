import React, {createContext, useContext, useState} from "react";
import baseUrl from './constants'
import axios from 'axios'

const authContext = createContext();

export function ProvideAuth({children}) {
    const auth = useProvideAuth();
    return <authContext.Provider value={auth}>{children}</authContext.Provider>;
}

export const useAuth = () => {
    return useContext(authContext);
};

function useProvideAuth() {
    const [user, setUser] = useState(null)

    const getAccessToken = async () => {
        const accessToken = window.localStorage.getItem('accessToken');
        if (verifyToken(accessToken)) return accessToken;
        else {
            const refreshToken = getRefreshToken();
            try {
                const response = await axios({
                    method: 'post',
                    url: baseUrl + '/auth/jwt/refresh',
                    data: {
                        refresh: refreshToken.toString()
                    }
                })
                const accessToken = await response.data.access;
                window.localStorage.setItem('accessToken', accessToken);
                return accessToken;
            } catch (e) {
                window.localStorage.removeItem('accessToken');
                setLoginStatus('loginNone');
                return null
            }
        }
    }

    const getRefreshToken = () => {
        let refreshToken = window.localStorage.getItem('refreshToken');
        if (verifyToken(refreshToken)) {
            return refreshToken;
        } else {
            window.localStorage.removeItem('refreshToken');
            return null
        }
    }

    const verifyToken = (token) => {
        try {
            const jwt_token = JSON.parse(atob(token.split('.')[1]))
            return ((Date.now() / 1000 | 0) < jwt_token.exp)
        } catch (e) {
            return false
        }
    }

    const login = async (username, password) => {
        try {
            setLoginStatus('loginWait');
            const response = await axios({
                method: 'post',
                url: baseUrl + '/auth/jwt/create',
                data: {
                    username: username,
                    password: password
                }
            })
            const data = await response.data;
            window.localStorage.setItem('accessToken', data.access);
            window.localStorage.setItem('refreshToken', data.refresh);
            setLoginStatus('loginSuccess');
            const result = await getUser();
            setUser(result);
        } catch (e) {
            console.log('loginError');
            setLoginStatus('loginError');

        }
    };

    const logout = () => {
        window.localStorage.removeItem('accessToken');
        window.localStorage.removeItem('refreshToken');
        setLoginStatus('loginNone');
    };

    const [loginStatus, setLoginStatus] = useState(
        verifyToken(getRefreshToken()) ? 'loginSuccess' : 'loginNone'
    )


    const getUserInfo = async (userId) => {
        const accessToken = await getAccessToken();
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/api/users/${userId.toString()}`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                }
            });
            return response.data;
        } catch (e) {
            return {}
        }
    }

    const getUser = async () => {
        let accessToken = await getAccessToken();
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/auth/users/me`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                }
            })
            const userId = await response.data.id;
            const userInfo = await getUserInfo(userId);
            return userInfo
        } catch (e) {
            return null
        }
        ;
    };

    const updateUser = async () => {
        let accessToken = await getAccessToken();
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/auth/users/me`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                }
            })
            const userId = await response.data.id;
            const userInfo = await getUserInfo(userId);
            setUser(userInfo)
        } catch (e) {
            return null
        }
        ;
    };


    if (loginStatus === 'loginSuccess' && user == null) {
        getUser().then(
            (result) => {
                setUser(result)
            }
        )
    }
    ;

    return {
        loginStatus,
        getAccessToken,
        setLoginStatus,
        updateUser,
        user,
        login,
        logout
    };
}