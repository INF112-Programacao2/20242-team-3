package com.inf_112.trabalho_final.util;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;

public class PasswordUtil {
    private static final BCryptPasswordEncoder encoder = new BCryptPasswordEncoder();

    // Gerar hash da senha
    public static String hashPassword(String password) {
        return encoder.encode(password);
    }

    // Verificar se a senha corresponde ao hash
    public static boolean checkPassword(String rawPassword, String hashedPassword) {
        return encoder.matches(rawPassword, hashedPassword);
    }
}

