# RAPTOR

The Ram-Air Parafoil Targeted Object Return (RAPTOR) system is an autonomous payload designed for the simplification of high-altitude balloon payload recovery.

The project aims to alter final landing location by deflecting an attached parafoil. An Arduino Uno will control two servos that can trim the parafoil's brake lines to change course.  

This repository contains all of the flight code used for the project, flight data collected and analyzed, and simulation files.

## 1. Payload Design Overview

The RAPTOR payload will contain a few consistent components across all iterations of the payload. The box is a simple styrofoam box, the exterior of which will be modified to hold servo housings. Inside of the box is the electrical components and sensors to drive the payload. The "brain" of the payload is an Arduino, which will both interact with environmental sensors and drive the outputs.

Every iteration of the payload must be able to fly on regular balloon flights with little to no matenience needed. With these major design considerations in mind, we will set out to build a reliable and reusable payload that can easily be attached to any payload line.

With iterative design in mind, our goal is to make each step simple and elegant. Thus, if there is an easier solution to a problem, we will take that. The goal is to add complexity only as needed over time.

## 2. Flight Software Design

The requirements for flight software are to maintain accurate measurements from a variety of sensors, be able to determine and make the necessary corrections to the flight path, and facilitate the safe descent of the payload train to the ground when over the landing zone.

## 3. Payload Iterations

### **Kestrel**

'Kestrel' is part of the naming convention chosen for RAPTOR as it goes through various design and developement stages. Kestrel is the smallest raptor in North America, and was chosen to represent RAPTOR's first iteration, or the '0.5' version of the project.

Kestrel was designed and built to be a testing payload, where we could fly our environmental sensors, continuous servos and solenoids to test their reliability and power consumption on a high altitude flight.

### **Falcon**

'Falcon' is the '1.0' version of the project. Falcon began when we made a completely new payload, with the plan of making our first real guided flight in mind. This is the first iteration of the payload with the parafoil attached, where all of the major flight goals for the project will be achieved. These goals include cut down, parafoil deployment, and guided descent.

![alt text](https://lh3.googleusercontent.com/08VQK_cJHctBsdPiarJFAllG-HUXjV4KG93Qopkh8PWqxyemp60GxGwwhsPvioKC6TSWX8pKGrXxwrKrk8XXFop7fkjdXXR2VQqJoVmNaJoeIMKOxXNGcJJWGRxl6ngI7tU0y4dk8F8qxxxXIOiQlOJHDu9Ewyy5v6tkaTxJccpZi2azrVgcxIcuTt60VYiX6FpkZL3SfdG3MiPHbuUhOVVtHrGEW2KVlTTCm7gdJeSQN4f5xzyVtL5Ereq8oW1eQlyvcNK1T95VWy89UnjDFjl_xIZf16y_2Z6-VHxamVH_8AvvuKVk4ZHFUJMEbMBIg8-7bgS1HJdt0UuZMx014c9ZiB7VgoNnlhHZwcHLAR7Pw0eCsOC7_Xq13sH98-pSVmey4UbFktCn4sBvILCpDKuoVDdpq6pLjYoRFDy5aARHPb9kLlaOdtlg4GMl1GkvqXEJoCu9Sruir3UPIOb3anZelVYQ76_zzmOLzB0DgU2jnw8FD_2lPsyYXJRQ2XWanfnDGW8nk8CmKOb-uKvsJVHz_Lf9Hoh2NGlCRr1trCBSoUCslre9NBD7_mv-Q1XIpGIQMr4Y3t4xc0uLkg_W5bK49CHts2PBNOsWoYgeCwW3V_xKcXlIQRmhrNYm_wV52q7rdRlzxCzd7h0K8jtAO66afkpGp139rfTcDMbF097igYaIkliFYCL3YA=w1158-h869-no "Falcon Payload with Parafoil Attached")

![alt text](https://lh3.googleusercontent.com/nTsq8ke9CdPrCzIl53acNa8SwdOpLuPSAk6aUb3CXytfzZnTHvZFV9xw1yQSyBJqHkr0cgnZ6tlVB8Kzcdpo9wiceyWq20kCEg2xDIhHhK3iLWAF6V_QYCNNu1fWfUKg2jkklAktDp1CagrbbR4zvm5fMbotnWXxVqoefFrQ5JEKGSgoutILIHwRJD0-UGI8wmyV4zEo2Ww0w9A62mWDVvDxTGenzbLDQ3pslx22jsCaGfgghKBvGALglWaCk9lZzjuBwkI2tjje7-YirwTb_FQy9pY9z9DQqCBEltGLZjhYR5o7yXRngFgwSk2WMsQNlL6hUlKJA0yVoo239JFV2wESlgw9OnhuMTLrr3tadC1-mG15Ya9mgoiJgZK8wNaf-toTZmSCUFcHcSYaXs-Wm4-cAaS_jDAta75yN-jv41pQ2eVJnnnB7EcDpv911wmj5ORR5dQ7spIRGRFnH9KPlVNNkSUa09xTTxY480m4pT42pYWwpdSlcoaxI6zaNZim3tZho3M7AVMkl9lsfFFffVUUj9iqBYh3hlCUjHGBxWbTxIfL7BEfSq9Zbd_mzikuakmANd_LMuXxTtnAjs-wiyw4AljWVypU6K3bTWPPjaUvIT4e4QJ-6-mMYwvwNSBDv8VlTkaO4NQXxIgIyaNhwofIzz1xATfFkZTSfx6gdJMR1wkdUpQkAOOw6w=w597-h795-no "Interior of Payload Pre-Flight")

![alt text](https://lh3.googleusercontent.com/qpwUnisi4AMiziGQZmHzRLYBiRqKub_Wn9nlaQfpf05oFm5Ekyx_R4OeDEhFKlS7zY80K_rwTjstmUsjaqJ_f78QGzWcw0SdS9lvnNbavl9Xdq8MnOOZnSqH13_WAorVAF_McEpw1rVnPtUOwhDlr9SZXShyw_HYdHsatmpSO8Iaw-kvdfDW1NLWaBeUKFKUjSlByxJ_tD8TH-3EEkSJU6_lpdmNE08wkrkFHSgYwGXVlp8_2iveOmKzGPOeyLg5UUH-xO01Xc0rjtU4FrM9aq0OHHgAeNhhn-Msrk1Q-X9tbxFfsy3EFknKx-CbDiHM6NEmQYi57d8fEFdIDXlz9nGxxgFrvg28Auc6FTR0M8zxlVvgmXc71kI5MRwZ0uz9A6vAbwkfQIcbghxKZlq6UTo1NPJRRolnA2FjLQT9UZB2dzWLNaw_X8Cfx9jBimqL7OulrpkwGK1UxH8sL2Yzj2OZSgqYgmGX-Jf7bW7pRk8I-UY5AWzCCYKbjxsp2XxTyTZCKdtj71aiyLx429-Y18rGXeBJwIlsL6IdDKQjU6Qo2SkH-ovcYIrsuhEMrVo9C0zi-aZg6P7hPZgUU_enA_p70k0WdAI0cCHYzM5wE1poVd9pJCcdmOx3lRhMei4g8gKIjZuI3atdYv35PfRt7ztj7EY-NizOeIiUlupoXuddiclaWPVx3sC4tA=w1061-h795-no "Falcon Payload During Testing")

![alt text](https://lh3.googleusercontent.com/5NEBB_IN66aADD8gVesJaUCWdb867f5fqQqcLy4GLZlCQvyXMMzAeoCJIVlz9DaSMwfq8yvq75xX2S32eSA2aUrFGHVeaQfilVyWKIKQhVMiaCQMRvjygylbysD2_IuR_qYD-yVYmDMRgYuOcTZqpBc72WcPrk61C2MFL6y4U4deJUnDy3k-_Vt4oSqk8UV3Gi4Cy6NLGP6pc4r56cdbB_oz8zaU3To_kvJVzvkHG-edpz9sEdex469MfbhWYxn7zSzdf_ULMe2hmKUT1Jl9ElcvvFhgkPS8XkG_Ln9uK_cCheCHhqK8AA-M47GPGyPQ1Z1R7Kh-4KDt0aD96zqOZOSrELtEydvk809B2evDbGKQKpu4Yrs5egNlsEguUiOS_33DcNpIEs5SEpjD5ZSTudhrpzj_77DZRZ23Sf8n5Pu5s58V_JVRcOfQb6ieYZJPw7966cbnYQJiViO1n6QoPUIqt2PKJKo-KAOjKYhyid7oeS0C2XUlqcRCxAsD41Ye13YNIbZHx-1l7ZGuJfxQdtHrh5wdzZg7fvCZLMXZnsBpbLtAVtSkC_K76j4hTMmp0bVdTCqAXRNUSvIgoLTFFcnFc3zld9tIdX5t2Q38Qa-OqhqdxeFUwVJHNWx_GisNrIGrjfOGCndxnQ7qL0WOhOF6yhU5_vznrhjJHDz56C57zfakUSOm7O0MCw=w960-h540-no "Team Photo 10/6 Launch")



#### *Falcon Testing*

[Parafoil Testing with Fake Load](https://photos.google.com/share/AF1QipOYNhcAF_VKSpH8EsGm9p09tWBEW8-P44Ib4esdOKR__pPn4U8IfVZbABBhkwzWkA/photo/AF1QipNYzDb1yor08mGMRFYyb5cecjjzEDNiWGI3c_8m?key=WWdJMzROREthYmZQbkcxRUtCUmRyaXJHUGVhZjln)

[Cutdown and Parafoil Deployment Testing](https://photos.google.com/share/AF1QipOYNhcAF_VKSpH8EsGm9p09tWBEW8-P44Ib4esdOKR__pPn4U8IfVZbABBhkwzWkA/photo/AF1QipNU7GBOfcRdJiM-u27gPR9Wuxxhj8X0IvZJd2tQ?key=WWdJMzROREthYmZQbkcxRUtCUmRyaXJHUGVhZjln)

[Parafoil Brake Line Servo Test](https://photos.google.com/share/AF1QipOYNhcAF_VKSpH8EsGm9p09tWBEW8-P44Ib4esdOKR__pPn4U8IfVZbABBhkwzWkA/photo/AF1QipONFaLqnrI26lueZZusB5zbdpsSCUT9ZnrO1FEE?key=WWdJMzROREthYmZQbkcxRUtCUmRyaXJHUGVhZjln)

[Parafoil Controlled Deflection Testing](https://photos.google.com/share/AF1QipOYNhcAF_VKSpH8EsGm9p09tWBEW8-P44Ib4esdOKR__pPn4U8IfVZbABBhkwzWkA/photo/AF1QipOjYvH4XpJ5j8LqXkNAdmoZCI6CpGh4pJOYzDQ6?key=WWdJMzROREthYmZQbkcxRUtCUmRyaXJHUGVhZjln)

## 4. Flight Reports

### **April 21, 2018** (UAH Space Hardware Club BalloonSat Flight 75)

Our first flight took the Kestrel payload up to 100,000ft, where the components performed nearly perfectly, with only three measured failures of a solenoid. The following graphs are constructed from the data collected during the flight.

![alt text]( https://lh3.googleusercontent.com/o0mIxF9JpTCW6p4-lqHFurN032vhSwak0O-0916o6F6O7LAnJ_aOQhJlaf2M4cd4pFyrAL5t6rdUJKfMR4ZkQsk-fCoIFAWFzNFy1YEiZ4ywFi4ZQsuEcB9D1KTloZXDjF0vYvFdRT8I6whbH9eXGDMrW1pF8fU-ode9iUjT89ON-45uyWiq1O6yWPkVVu-d5cUqWAT0grQv5DsArr3dlqi4KNMW4X2lQBzKB5s9GIfAufiF1Di9rTAAF0E3c74gfjZwB-d6Ytg9FaDoTxDn2MhPcVrfUKBEtZKRTLo8erD8Vgq89sy1f4834WoS8XgF5q_Wi7MSM2GpKTmqX_B2gydXwuPWlM3H_2TrWNvwGbhPs-MXHr6mVQXRII_N9rgdHwJk_Zw4FyJ0VciDm9MFl3ktjZEayzCG4I1Irl8m6_wDF_QWiISo4ycMos6EsyfTj1rtdBza8v9ezVyRnK6vijcEkrmjineadoEkculacf6ZdSMiAklYv6Ft1EMe6fH91DpYTu-vJQEyVPyUjGvEnvXAZhmuQV4eM_kY-27H0Y-Ny4zwNg4yrA3Hd2eUDqEm4s_CRX5Cdk5N-sFd7zbHQK70AVQ9KG8g7XHPbRM0v_tN7a6QpNNvVbvWWc_uqCJJ=w640-h480-no "Pressure vs Time, with Solenoid Failure Markings")

![alt text](https://lh3.googleusercontent.com/xaKkXQC05gPxcVHP6FCj9-jyQXmJgc9uEEoBEQZimM55ZY58FsezMpbSfdpHoBNiei0WVD3Qnf3msswCOKAefwGBVAnoBPBxKHqaxiV7dBAGgjgWg5DIxJb4xZl9eh57vn1u6YbPOBlRteAb5n9VeIBRhydFzZTUslWns0vXSZVCM1zK54HaJHy2MT-dDtrz7ZPDDayoTF1qfZ3y3p8BGVbADIyd97ayQYDKrkhpLw7GynPQWuwVw7QnTFyjEoOa1aux0NvpnPhppEcE9dWlhF780ChDJz-0UJfwPGzB0nEWA4IR-9vzoHCnrm1v3vLtHpdkeYzmoI01gz9HVwItqfs2kdfuWgmZYQjfPcJVxFNqH_63nlPkzpoLTvQk2hnIWzQxQABk3G-Ru3Mu8ikYkJ8hdk5VBWTOS5p6dLuzM6voH9KjLJA-3Sl3eEbHG2ppDa8y4gKdePih2BsavPeFtxRbqSdFP6xtOUOgWm9_ZxbqCyWmKqEKwNEIJkaCxk6LfHnjetM6RkAFVx0QHQ9FYjHE1f0gKdSpCGsWQL-pN6cg5KlEpgvO3ia1LeHBieXHkT3OqZLvgvxPcbomJ1y7S_N_ohK648aIuNCY1nCs9VQt-EV4mmqJ7JmVbDW8L6wl=w640-h480-no "Temperature vs Time, with Solenoid Failure Markings")

![alt text](https://lh3.googleusercontent.com/yJp7Rl4tlh0OgynnB0pwqxiqb4GSry8reSSILUXDwRd5CED4hvreXAOTxB36PlfS6nvmWq1V5MiOyp7Bis8rF3g8JE0Oqanw4t9SUEjYtItWJUzEscm9GlXeQy7c87zzbjJ_WzJdIuUwWjhM93PkIns-0FYcOpU8xDzCH6Ze0wD2_3bIjE-ypP3AcKUHbIJy4IUB86maOxbvp_ImD1bnjD6u1Gk7OkCzfXJR9hdCCMFqlngcm56nwWZbPGF4-TE0t63B0GotCJmi-IbmLTaqOmXq_UMarg7PiEs0iMEoNK_E3CIcfkmG6do2ifHMahkhrlXl-hDUADyxodFllPnLSKQCDogX26wtK_2kbTWECWZgkv6bbQi-hTY4Z7aDev4EhqDO0LPZ4bpZMD6goSjPPxSNEnR5Et_jjw9HPDWlF-xWUBQAuQz-VHXZf1wwIPo4YJ-hfvKorc5dKjW8jGdo93sgWYhCdh1y8_lIsHr_W2Ll5liXtCqrEy8m_VX4kIWQMELzsu1o07mh7myIgIqpDSEzJ60L7k321RNn8hDGWb2Y82E0vZ5qvwWa8ZqKYH6OXC4CJ-Vjt-3qjoJtlSXHhQlk1cRW6SRVriCUeESZMsNHbSpocSI1EeN2J4-sQ-jB=w640-h480-no "Pressure vs Time, with Solenoid Failure Markings")



### **August 31, 2018** (UAH Space Hardware Club BalloonSat Flight 77)

For our second flight we gathered additional data using the Kestrel payload. A major issue during the flight was that the Arduino power cycled while near the apogee of the flight. Due to a mistake in the code, a baseline pressure is taken when the board initializes, so the altitude during descent tended into the negative values. The following graphs show adjusted data from the flight for ascent. There were no recorded solenoid failures during the flight.

![alt text]( https://lh3.googleusercontent.com/MRX_bFXJetOg1aB5wNyvmU14bfMBnIYrwlvbJ33pcFYwK6eS6S0-DdBDFQAEzepfaU3I5fB7g92ceOtPr6XYwi1YCWP-x7m_2AGui4MWdTZrSNywGwxau3owqjKPpeeZUny2l0pn1MOlpMqQ20K6BCVZTGqwuC7kwrzOFIgUzXGwmAfB0ekMsaITRGZdgXwXdmsAggmIbNeSjNlQPk93jis5PHzP36B16HXys2YhrETZSeMsoAYaYcLBfj6TQVnkGIt4KjXCtmLzlX0hDQCnojHSTsDNCEYKwSSBIGwgC63nlx_tCBwfBRz1vaOT4HpYefGkBPbjTHI4y8XFsqdH1_NdS-EyLARis9voy_CYtdYBrDJThR_byuLnX-rFLZzUAeYC7NIKQwe9YQZYjeGgxumcal7syeeRWw7Db57jgAqSzRGrgNLYgbMlF5YhL6zevIkDWZIZRbo2P6brQTfT1VVhcyv4E0c53xYCO6-WRWP2jEPRoAi6mMK5i_LqX-Oi9SixEdleJFEZBeSg1FddV6_2ck3GULUwaYqlb62A_i1iivpWswBQMbQcrlfooHw36Z8GwE9VHq0Y8PTFiJtFiV19U-L_uRMUOd5EKPpKY64eQ37eIV5pcy_00pmtQpN2=w640-h480-no "Temperature and Altitude vs Time")

![alt text](https://lh3.googleusercontent.com/Y4CDoAoS2dIhLRWhnF7a5mxLAkN89WYJ-2H63kcUrKUIaF_1hElJlrU4Xk-xMh04kAqPIyo8T-RROAUbGWmkpqQO6P9UKqv96oe9mTNt2_tanveFWIan3q2ELKeRTuSr3td5RkJul22HY_6ouphoeI_AsPE4-tTNlo2N8ON2lWaVqY-2vvBoBxMCbHlcg8GFzQMku9e32KSeSX4C0cYXz6I8k5JIgeUyMapub-uarkHK1aHVDsjtfC6V47vI_da9QKYYjJP0ap2yFbNyIIDTO1j3ZboP_w2OZzkLhzYqhA2TnYVuEJgcOFwX4ea7ON4U_dtl4BuTxPq2_tGN6nfwM7GqFqyxppiiFBl31SAOE_78_Gi9wOf0qVMZ5w3yPUdJQBoqnGU4FjI3PNAeO7GuXJay-DZE6UTzwhg8iAQMlJRYKTHLpM7AoLEDopjvttDvmFO1kuAvGXok041ZXf7-QEJ8VhcDApRYzauS4llMR63rekm26FqyFbx3VO1KY-YRqmbg-JcjKtY8mvfco_xXvZbSsjWH9RAF85HJPx8p74FAhuvl5fxnYFZ2vNsHbuQdQO_uPbo-vgZvpiPrqXuvja5mqghplvSWkdiv8-zjK0-YLwJM_pEZ4y4VtR5f7UYY=w640-h480-no "Temperature and Pressure vs Time")


### **October 6th, 2018** (UAH Space Hardware Club BalloonSat Flight 78)

//
