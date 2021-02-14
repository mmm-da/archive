import React, {createContext, useContext} from "react";
import baseUrl from './constants'
import {useAuth} from "./useAuth";
import axios from 'axios'

const apiContext = createContext();

export function ProvideApi({children}) {
    const auth = useProvideApi();
    return <apiContext.Provider value={auth}>{children}</apiContext.Provider>;
}

export const useApi = () => {
    return useContext(apiContext);
};

function useProvideApi() {
    const auth = useAuth();

    const getThing = async (uuid) => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/api/things/${uuid.toString()}`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                }
            });
            const data = await response.data;
            return data;
        } catch (e) {
            return null
        }
    }

    const getStorage = async (uuid) => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/api/storages/${uuid.toString()}`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                }
            });
            const data = await response.data;
            return data;
        } catch (e) {
            return null
        }
    }

    const postStorage = async (name) => {
        let accessToken = await auth.getAccessToken();
        const username = auth.user.username
        try {
            const response = await axios({
                method: 'post',
                url: baseUrl + `/api/storages/`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                },
                data: {
                   name: name,
                   owner: username,
                   sections: [],
                   tags: []
                }
            });
        }catch (e){}
    }

    const patchStorageName = async (uuid,name) => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'patch',
                url: baseUrl + `/api/storages/${uuid}/`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                },
                data: {
                    name: name
                }
            });
        }catch (e){}
    }

    const deleteStorage = async (uuid) => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'delete',
                url: baseUrl + `/api/storages/${uuid}/`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                },
            }).then(
                async ()=>{
                    await auth.updateUser()
                }
            );
        }catch (e){}
    }

    const getSection = async (uuid) => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/api/sections/${uuid.toString()}`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                }
            });
            const data = await response.data;
            return data;
        } catch (e) {
            return null
        }
    }

    const getInstance = async (uuid) => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/api/instances/${uuid.toString()}`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                }
            });
            const data = await response.data;
            return data;
        } catch (e) {
            return null
        }
    }

    const getCategory = async (uuid) => {
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/api/category/${uuid.toString()}`,
                headers: {
                    Authorization: `Bearer ${auth.accessToken.toString()}`
                }
            });
            return response.data;
        } catch (e) {
            return null
        }
    }

    const postThing = async (name,description) => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'post',
                url: baseUrl + `/api/things/`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                },
                data: {
                    category: '',
                    name: name,
                    description: description,
                    tags: [],
                    things_instances: []
                }
            });
        } catch (e) {
            return null
        }
    }

    const postInstance = async (count,thing,section) => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'post',
                url: baseUrl + `/api/instance/`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                },
                data: {
                    count: count,
                    type: thing,
                    section: section
                }
            });
        } catch (e) {
            return null
        }
    }

    const getThings = async () => {
        let accessToken = await auth.getAccessToken();
        try {
            const response = await axios({
                method: 'get',
                url: baseUrl + `/api/things/`,
                headers: {
                    Authorization: `Bearer ${accessToken}`
                }
            });
            const data = await response.data
            return data
        } catch (e) {
            return null
        }
    }


    return {
        getStorage,
        postStorage,
        patchStorageName,
        deleteStorage,
        getSection,
        getInstance,
        getThing,
        postThing,
        postInstance,
        getThings
    };
}