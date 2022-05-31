import React from 'react';
import { View, Image, Text, TouchableOpacity } from 'react-native';

import succesImg from '../../assets/success.png'
import { Copyright } from '../Copyright';

import { styles } from './styles';

interface Props {
    onSendAnotherFeedback: () => void;
}

export function Success({ onSendAnotherFeedback }: Props) {
  return (
    <View style={styles.container}>
        <Image
            source={succesImg}
            style={styles.image}
        />

        <Text style={styles.title}>
            Agradeçemos o Feedback
        </Text>

        <TouchableOpacity style={styles.button} onPress={onSendAnotherFeedback}>
            <Text style={styles.buttonTitle}>
                Quero enviar outro
            </Text>
        </TouchableOpacity>
        <Copyright/>
    </View>
  );
}