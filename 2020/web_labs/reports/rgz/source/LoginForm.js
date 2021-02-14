import React from 'react';
import {Redirect} from 'react-router-dom'
import {useForm} from "react-hook-form";
import {useAuth} from "../../useAuth";
import {Spinner} from "../Spinner/Spinner";

export default function LoginForm() {
    const {register, errors, handleSubmit} = useForm();
    const auth = useAuth();

    const onSubmit = data => {
        auth.setLoginStatus('loginNone');
        auth.login(data.username, data.password);
    }

    const formBody = <form onSubmit={handleSubmit(onSubmit)}>
        {errors.username && <p className='form-error'>{errors.username.message}</p>}
        {errors.password && <p className='form-error'>{errors.password.message}</p>}
        <div className="form-input">
            <p>Имя пользователя</p>
            <input
                name='username'
                autoComplete='username'
                ref={register({
                    required: "Без имени не получится."
                })}
            />
            <p>Пароль</p>
            <input
                name='password'
                type="password"
                autoComplete='current-password'
                ref={register({
                    required: "Пароль нужно ввести."
                })}
            />
        </div>
        <button type="submit">Войти</button>
    </form>;

    switch (auth.loginStatus) {
        case('loginWait'): {
            return (
                <Spinner spinnerSize='medium'/>
            );
        }
        case('loginError'): {
            return (
                <>
                    <p className='form-error'>Неверный логин или пароль</p>
                    {formBody}
                </>
            );
        }
        case('loginNone'): {
            return <>{formBody}</>;
        }
        case('loginSuccess'): {
            return <Redirect to='/'/>
        }
    }
}

