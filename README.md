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

![alt text](https://lh3.googleusercontent.com/1o9nY4RvOQGDZTQBY0d3M0oymKL5FPMcOie_QyGTn0_0s2nfabPlYtp4XrS53vgEl31j4T295NOKGKeISqotcockGwPX17MacXHBMp5uQQhCgSTBN3fivYLe4FH1sv7LIwD_jMzwX0xuYfu2I7zcKqNWYCED4FGPxXIC2lp9WhjVXdyVxlG2mypMxBv7matItwner1dqWoc0-8VIdjEP2aFd7tcvNrXtY4KThVsYXTu_WTHsyYvhj51TiOX4oJQbpk91M41Vuaf-9wlotDnrBLGKEyYNOQSero3I_h9XqgsIIMKDaJQmmzK8gyGDPt9G3sRPc0t0jdvQOY7Kxvdpk4dimrI1KPCLvvKjmj8Sz7qjrb2Eb4AjAmUVQbY7hBT8Okc2IodMNK_0iG5RgeYsRDUH2gYtrwl3cdZvUf_Mb-ik4wDyqlk3FPh8wue_QHCtcDMfmFxLXnh9t6I8pjCoASx5NAmAlmIxECGQ_wFuVaCft_TXxiOwZVAJDaJE92KxI8Y-hB9OsX4ng2PsiRiAATfGO9ljCzctCG4QH-NFaGL2eXsTI1lXqa00m9X3xakB2D8HhrWGXt4zMbiEPQ-2WborEbNJ8yWgcpgkalNCoLOwa_rXh5JL0O369-iPGqds=w960-h540-no "Kestrel Payload")

![alt text](https://lh3.googleusercontent.com/uCabqWDjVLErh2zyCXdYhAvNTMVmv-jxHRv1PDopmbwNDc_ZhoJPY0nD8ILytu6s-EueVPPUXQ7v6TyP5FRkylkzkazS8X3QIo4R5wyPkX31q6gQq4APF3gKN9XSp_Dt44Vdsq1YEE2CmP70erqQ0DhAi5DR7h9X1DM_-2GV2KdjlvnUFyNTl2FYeX3XFMNITLKFNQT7BZ-cslzGhfotNse5TQvgF8SWa8zwI5sBvG5sqhCEWqRPrAY4oqOD3pu79el5zKrv0qsWF-xrm5Ls2jfoTOdaY_gpDyNWutr9rxEPsdRphLtD28V7YR718-XnSSSm8Fimq3ziECka6WFPRJVwvYon4FY47tEDq548RPfXXtSEArf0KaLQL65_61WVpear43DuSzeMtCiT-i8kJnIbIIhYUiEeRsqtAf_WZ5QGarYjHyU9IRfzgBt9K1IkYggcD2KOjFwM21JyoFTrhuFFB2gNLcNIE2LP2iEJCXGodx1lFC1X6oU3ghkXyX1M4zr7brOwbnr8k1rE-myAJ8-a4IQ_BKBpdJr7nCeX4oSjcwZGjMvmOZev2VF-u0I3nYhr1Q2IQwIiFYxZMD7EenbLzF8bkhLI7VkrZSnE357Cre0VkcDc1z18odNdE8Xp=w960-h720-no "Kestrel Payload Interior Pre-Flight")

### **Falcon**

'Falcon' is the '1.0' version of the project. Falcon began when we made a completely new payload, with the plan of making our first real guided flight in mind. This is the first iteration of the payload with the parafoil attached, where all of the major flight goals for the project will be achieved. These goals include cut down, parafoil deployment, and guided descent.

![alt text](https://lh3.googleusercontent.com/08VQK_cJHctBsdPiarJFAllG-HUXjV4KG93Qopkh8PWqxyemp60GxGwwhsPvioKC6TSWX8pKGrXxwrKrk8XXFop7fkjdXXR2VQqJoVmNaJoeIMKOxXNGcJJWGRxl6ngI7tU0y4dk8F8qxxxXIOiQlOJHDu9Ewyy5v6tkaTxJccpZi2azrVgcxIcuTt60VYiX6FpkZL3SfdG3MiPHbuUhOVVtHrGEW2KVlTTCm7gdJeSQN4f5xzyVtL5Ereq8oW1eQlyvcNK1T95VWy89UnjDFjl_xIZf16y_2Z6-VHxamVH_8AvvuKVk4ZHFUJMEbMBIg8-7bgS1HJdt0UuZMx014c9ZiB7VgoNnlhHZwcHLAR7Pw0eCsOC7_Xq13sH98-pSVmey4UbFktCn4sBvILCpDKuoVDdpq6pLjYoRFDy5aARHPb9kLlaOdtlg4GMl1GkvqXEJoCu9Sruir3UPIOb3anZelVYQ76_zzmOLzB0DgU2jnw8FD_2lPsyYXJRQ2XWanfnDGW8nk8CmKOb-uKvsJVHz_Lf9Hoh2NGlCRr1trCBSoUCslre9NBD7_mv-Q1XIpGIQMr4Y3t4xc0uLkg_W5bK49CHts2PBNOsWoYgeCwW3V_xKcXlIQRmhrNYm_wV52q7rdRlzxCzd7h0K8jtAO66afkpGp139rfTcDMbF097igYaIkliFYCL3YA=w1158-h869-no "Falcon Payload with Parafoil Attached")

![alt text](https://lh3.googleusercontent.com/nTsq8ke9CdPrCzIl53acNa8SwdOpLuPSAk6aUb3CXytfzZnTHvZFV9xw1yQSyBJqHkr0cgnZ6tlVB8Kzcdpo9wiceyWq20kCEg2xDIhHhK3iLWAF6V_QYCNNu1fWfUKg2jkklAktDp1CagrbbR4zvm5fMbotnWXxVqoefFrQ5JEKGSgoutILIHwRJD0-UGI8wmyV4zEo2Ww0w9A62mWDVvDxTGenzbLDQ3pslx22jsCaGfgghKBvGALglWaCk9lZzjuBwkI2tjje7-YirwTb_FQy9pY9z9DQqCBEltGLZjhYR5o7yXRngFgwSk2WMsQNlL6hUlKJA0yVoo239JFV2wESlgw9OnhuMTLrr3tadC1-mG15Ya9mgoiJgZK8wNaf-toTZmSCUFcHcSYaXs-Wm4-cAaS_jDAta75yN-jv41pQ2eVJnnnB7EcDpv911wmj5ORR5dQ7spIRGRFnH9KPlVNNkSUa09xTTxY480m4pT42pYWwpdSlcoaxI6zaNZim3tZho3M7AVMkl9lsfFFffVUUj9iqBYh3hlCUjHGBxWbTxIfL7BEfSq9Zbd_mzikuakmANd_LMuXxTtnAjs-wiyw4AljWVypU6K3bTWPPjaUvIT4e4QJ-6-mMYwvwNSBDv8VlTkaO4NQXxIgIyaNhwofIzz1xATfFkZTSfx6gdJMR1wkdUpQkAOOw6w=w597-h795-no "Interior of Payload Pre-Flight")

![alt text](https://lh3.googleusercontent.com/qpwUnisi4AMiziGQZmHzRLYBiRqKub_Wn9nlaQfpf05oFm5Ekyx_R4OeDEhFKlS7zY80K_rwTjstmUsjaqJ_f78QGzWcw0SdS9lvnNbavl9Xdq8MnOOZnSqH13_WAorVAF_McEpw1rVnPtUOwhDlr9SZXShyw_HYdHsatmpSO8Iaw-kvdfDW1NLWaBeUKFKUjSlByxJ_tD8TH-3EEkSJU6_lpdmNE08wkrkFHSgYwGXVlp8_2iveOmKzGPOeyLg5UUH-xO01Xc0rjtU4FrM9aq0OHHgAeNhhn-Msrk1Q-X9tbxFfsy3EFknKx-CbDiHM6NEmQYi57d8fEFdIDXlz9nGxxgFrvg28Auc6FTR0M8zxlVvgmXc71kI5MRwZ0uz9A6vAbwkfQIcbghxKZlq6UTo1NPJRRolnA2FjLQT9UZB2dzWLNaw_X8Cfx9jBimqL7OulrpkwGK1UxH8sL2Yzj2OZSgqYgmGX-Jf7bW7pRk8I-UY5AWzCCYKbjxsp2XxTyTZCKdtj71aiyLx429-Y18rGXeBJwIlsL6IdDKQjU6Qo2SkH-ovcYIrsuhEMrVo9C0zi-aZg6P7hPZgUU_enA_p70k0WdAI0cCHYzM5wE1poVd9pJCcdmOx3lRhMei4g8gKIjZuI3atdYv35PfRt7ztj7EY-NizOeIiUlupoXuddiclaWPVx3sC4tA=w1061-h795-no "Falcon Payload During Testing")

#### *Falcon Testing*

[Parafoil Testing with Fake Load](https://photos.google.com/share/AF1QipOYNhcAF_VKSpH8EsGm9p09tWBEW8-P44Ib4esdOKR__pPn4U8IfVZbABBhkwzWkA/photo/AF1QipNYzDb1yor08mGMRFYyb5cecjjzEDNiWGI3c_8m?key=WWdJMzROREthYmZQbkcxRUtCUmRyaXJHUGVhZjln)

[Cutdown and Parafoil Deployment Testing](https://photos.google.com/share/AF1QipOYNhcAF_VKSpH8EsGm9p09tWBEW8-P44Ib4esdOKR__pPn4U8IfVZbABBhkwzWkA/photo/AF1QipNU7GBOfcRdJiM-u27gPR9Wuxxhj8X0IvZJd2tQ?key=WWdJMzROREthYmZQbkcxRUtCUmRyaXJHUGVhZjln)

[Parafoil Brake Line Servo Test](https://photos.google.com/share/AF1QipOYNhcAF_VKSpH8EsGm9p09tWBEW8-P44Ib4esdOKR__pPn4U8IfVZbABBhkwzWkA/photo/AF1QipONFaLqnrI26lueZZusB5zbdpsSCUT9ZnrO1FEE?key=WWdJMzROREthYmZQbkcxRUtCUmRyaXJHUGVhZjln)

[Parafoil Controlled Deflection Testing](https://photos.google.com/share/AF1QipOYNhcAF_VKSpH8EsGm9p09tWBEW8-P44Ib4esdOKR__pPn4U8IfVZbABBhkwzWkA/photo/AF1QipOjYvH4XpJ5j8LqXkNAdmoZCI6CpGh4pJOYzDQ6?key=WWdJMzROREthYmZQbkcxRUtCUmRyaXJHUGVhZjln)

## 4. Flight Reports

### **KESTREL**

#### **April 21, 2018** (UAH Space Hardware Club BalloonSat Flight 75)

Our first flight took the Kestrel payload up to 100,000ft, where the components performed nearly perfectly, with only three measured failures of a solenoid. The following graphs are constructed from the data collected during the flight.

![alt text]( https://lh3.googleusercontent.com/BemMeG_wjjgEnfAlytIrjKeVrs0k2_3DL499e8Ap5Oft2oVPp0bTjnTxFLzm9G5_wCgSZQKKXPSeFjSZQ_YwVKfhydMyssC7hJiGl_VFefC5Ld4zEoicfH3cAaqB6fmjJgoYrH05eeumFNejKm7PjL46E2_nqWuUK5U6rI2XySVey0R1O4OTPtHjYdG99H4zouDzcY32j3y5tLoOQnTtlBcOFRQ8rH2lUBEi35j89AvM8G2c90CDi0v2CoHU7czhbz966LqDCKfWzz_Uu0tOuIzP930aPOUN7lcU77oL2ur3KDhcqeuWbX8ei-HmRiuW3BXLsKMlipR4F8ocsBWXwEvi9D2h8oI47lwhvOTEdysgULMQIh_SykLWEu4uhSGmnOfd1YHDiI4w3XNgK1TuH1m_afvcnSUPijgbQb5HaiK8aGwG3VhtvdcM13aHrT663Zl56MrhRvBEeC2diIdCjywXDfGZ8eANmSSOaxT0NINNAg2Y1RtrVUbsQjtTjYA55fDqOdL7a4vx8JRkxYpg6WzqFhFfQ36Xjsuhh99Qhh1iIdaOTVb9rApYPM6s0g09yX5pHvM8OQDPl-Lv8vEm45jswifNxpu0n3VRAGOUArKucUweFrDAMBllAYfaRtu-fDxdC5_WFBRoDsw6rybttKe9au_GFPDHYdJCznGXMXrvVw=w408-h306-no "Pressure vs Time, with Solenoid Failure Markings")

![alt text](https://lh3.googleusercontent.com/KNZ6x_Vac3x1Pnvgrhe8NedKYn2VLNuSEfFBFWm-Lp36aQMo7iNe9pHYzUXd3TR03b9J4sRoP69VhWtRAomjtsnrsVQ_ZSnNuRpuq2FJL7O_-B3BK03cpRlcjrfZnnfZXRXjz6CxwUeIPqneTGVKDhtemaREcjrmKWXwKW3u9_gxcjQQzsbOZ21y_vO-62-NJt1KZl_tUMLYdPYTev9oHmAjZRZhO2ZE-4TkEKHpc2GtuKhXlguC7bCiIMqft2PSBXj9gHzH8xiNaVe1EM6CjY3udydmxBZB3ITQOPuKURP9T_vBdbWoPDJWirycvGVW7Uc2pf9EKVr8SSTTZgMCJw410q722htsQWmkcO69iLZ1mfWPXfPV2p51zg97J6a9MHCTXy4jRaJMe0iM64E5n6J5ZQKTfwVYPfBKYd7POWQr4uGVoA6mlpYatiOPDqaDP7u6AOJVOlHibj6QEbTqPC_VZAfjKfWG0iumFLhjhwJloQni4_ZA2aNHW66xsAubR205tuTrD5F-u5X4U0qCqha_3RRW8oNNcotxu7BR2zmIoKq2WZr8Kp3AZ3PQM47FAguCEMu-JxX63GBR1raVn48RD1BE1BixgWTI0Daso8u6qyi6rDZfGTG2SE0nGrZXXJ6XzwochKAMBll-vfNgwUO0bIXTk_1-cqaIEuWl82EfmA=w640-h480-no "Temperature vs Time, with Solenoid Failure Markings")

![alt text]( https://lh3.googleusercontent.com/LbfyWvzu6PWR8G42ObNfinUGaMZgHTH2ggLDe802Y7b2Mt4PNNAm9G_F5JisICvvmlPLEjyTsWcb9FliGdE-NDNIIxiNTZ3leAKVSWQcmAyk3ySunhAUJf4kC4v4u73iBjNsuHjP2WlYzTTyxFHMk6qMPHSMiaM_Dvg5iQcWo8bOIR5vz0KfVyvxNrVATn4UMsQZBBMJXErHtUJM_63gZdhM8AneoD_rhRJiUTecDVIreZXYB0VBPlZl4TrYMDCLdlFwZfcVm2BamQi4z1MdMlEVq4y4cX0ujoqyfffoRjWKA8LNmyCLOK_hThx6u1NnOF3T1R21sCSxTRCCmbXvTDSkyp7HBMa3JckRKfF5wFPYv8Wkl4oTQPiuo-lON8dz39avKVW11d7X9vgXGXMDaclX2pUxBHPYkQ2QgSGmlQcPx-6kFGojLVLShEcnWrYTRloLN6BGV0cArWn79ekvIfFnemd5E0d4xmwKIOAJfLM5Ds-5fETZlfScP4Vl-QQu5exSGAfbesk8ioKyGFL-NTCuzRXI3Qy7nNCyFQdaBkEx4lMR0ScLJH1lECmvgC9p0kOkZfx7-EwR241fS4VFVr81lbcC1-R4HPC1hSJ5HVVyXz86KfrtZx50OQnzqxn_5QQbVOpNjmxgJx9FIdSDdZ2GXakEOqzYJ5Alb4JiiRlSLw=w960-h720-no "Team Photo")

Additional photos: https://photos.app.goo.gl/y1GM2Ua3seM8kpAX6

#### **August 31, 2018** (UAH Space Hardware Club BalloonSat Flight 77)

For our second flight we gathered additional data using the Kestrel payload. A major issue during the flight was that the Arduino power cycled while near the apogee of the flight. Due to a mistake in the code, a baseline pressure is taken when the board initializes, so the altitude during descent tended into the negative values. The following graphs show adjusted data from the flight for ascent. There were no recorded solenoid failures during the flight.

![alt text]( https://lh3.googleusercontent.com/MRX_bFXJetOg1aB5wNyvmU14bfMBnIYrwlvbJ33pcFYwK6eS6S0-DdBDFQAEzepfaU3I5fB7g92ceOtPr6XYwi1YCWP-x7m_2AGui4MWdTZrSNywGwxau3owqjKPpeeZUny2l0pn1MOlpMqQ20K6BCVZTGqwuC7kwrzOFIgUzXGwmAfB0ekMsaITRGZdgXwXdmsAggmIbNeSjNlQPk93jis5PHzP36B16HXys2YhrETZSeMsoAYaYcLBfj6TQVnkGIt4KjXCtmLzlX0hDQCnojHSTsDNCEYKwSSBIGwgC63nlx_tCBwfBRz1vaOT4HpYefGkBPbjTHI4y8XFsqdH1_NdS-EyLARis9voy_CYtdYBrDJThR_byuLnX-rFLZzUAeYC7NIKQwe9YQZYjeGgxumcal7syeeRWw7Db57jgAqSzRGrgNLYgbMlF5YhL6zevIkDWZIZRbo2P6brQTfT1VVhcyv4E0c53xYCO6-WRWP2jEPRoAi6mMK5i_LqX-Oi9SixEdleJFEZBeSg1FddV6_2ck3GULUwaYqlb62A_i1iivpWswBQMbQcrlfooHw36Z8GwE9VHq0Y8PTFiJtFiV19U-L_uRMUOd5EKPpKY64eQ37eIV5pcy_00pmtQpN2=w640-h480-no "Temperature and Altitude vs Time")

![alt text](https://lh3.googleusercontent.com/Y4CDoAoS2dIhLRWhnF7a5mxLAkN89WYJ-2H63kcUrKUIaF_1hElJlrU4Xk-xMh04kAqPIyo8T-RROAUbGWmkpqQO6P9UKqv96oe9mTNt2_tanveFWIan3q2ELKeRTuSr3td5RkJul22HY_6ouphoeI_AsPE4-tTNlo2N8ON2lWaVqY-2vvBoBxMCbHlcg8GFzQMku9e32KSeSX4C0cYXz6I8k5JIgeUyMapub-uarkHK1aHVDsjtfC6V47vI_da9QKYYjJP0ap2yFbNyIIDTO1j3ZboP_w2OZzkLhzYqhA2TnYVuEJgcOFwX4ea7ON4U_dtl4BuTxPq2_tGN6nfwM7GqFqyxppiiFBl31SAOE_78_Gi9wOf0qVMZ5w3yPUdJQBoqnGU4FjI3PNAeO7GuXJay-DZE6UTzwhg8iAQMlJRYKTHLpM7AoLEDopjvttDvmFO1kuAvGXok041ZXf7-QEJ8VhcDApRYzauS4llMR63rekm26FqyFbx3VO1KY-YRqmbg-JcjKtY8mvfco_xXvZbSsjWH9RAF85HJPx8p74FAhuvl5fxnYFZ2vNsHbuQdQO_uPbo-vgZvpiPrqXuvja5mqghplvSWkdiv8-zjK0-YLwJM_pEZ4y4VtR5f7UYY=w640-h480-no "Temperature and Pressure vs Time")

### **FALCON**

#### **October 6th, 2018** (UAH Space Hardware Club BalloonSat Flight 78)

Our flight on October 6th, 2018 was the first flight of RAPTOR payload Falcon. The intent of the flight was to fly on the UAH SHC One Month flight and cutdown from the payload train at 800 feet. Upon release from the payload train, the payload would drop 25 feet and deploy a parafoil, beginning guidance toward a designated landing point.
Payload Falcon was the second from the top payload on the flight train, just below the master cutdown and above of all of the other payloads. The intention being that Falcon would release prior to the master cutdown altitude of 1000 feet and after the other payloads had released from the line at 500 feet, clear from our flight path.

During the flight, Falcon successfully released from the payload train at 800 feet; however, as it fell from the payload train it got caught on the parachute bag of the payload directly beneath Falcon. After Falcon got caught on the parachute bag, it was entangled and proceeded to fly with the payload train until the master cutdown released from the balloon. Falcon then fell under the influence of the master cutdown’s parachute and was recovered safely.

Post flight, through inspecting GoPro footage and recorded telemetry, it was clear that Falcon successfully released from the payload train and deployed the parafoil; however, it was simply entangled in the parachute bag. Even though Falcon became entangled, there was still several takeaways from the flight.

First we learned that both the balloon and parafoil release mechanism worked correctly. We proved that the electronics were able to power and sustain a short flight, we showed that the coding was able to cycle through all of the flight states correctly. We also found that the GPS receiver was reporting altitude in MSL instead of AGL, which could have negative effects on future flights. Data recorded to the SD card was formatted incorrectly, making it difficult for post-flight analysis. Finally, we learned that our flight checklist was missing several steps, including how to properly start the GoPro cameras.

![alt text](https://lh3.googleusercontent.com/LHJe6HiXcIz81Ea09SGUOwY1y3NmHhyFWJHuItK7zjxrx4ana2Pq6K-i-WVNmY_tG5ZWHFH_c-4tZLxe9ZF3UkqxDCNr89Ehnhs_neyA-6rPpHWl1EMa-16J-t3yzjn635yeT2SOOcQfsKbD-lygc3FDD9CbBD1JcXLitXUJ8VvJEq86ejSRDGlAnCPRIqmc9vx3McO0qJSqdnxA4UqmKZT4iqblNqUXxdsLiUXPwJeeFhbe_hfN6wz7SrPd_j9WRm7WbuIqJjOQ36e0r7RbVSuY_wfmJQcTNMCIMEioEV7koDCaNOlq1_myfCfjCbSitLBeFj_QklhKbJHZzHGQ5S-43_EJiz4XPnSHKFZah8RNivv9W01RpwN9SoXH3iwLcoo_Rzzfn2p6MuiC4960lPCptIiZR6s2hcoQnX65pIhsCLfu7xhbroYqcwg16WNTlj8OfoDzCQn7fD71CB55G6uvt8AhauzKEpGWpnL5V-hp_4lNYRRE_z6id8nEweK-y5KfxRa9ROIM8IhCa6QzceIUBz572YB3A3QvGto9w4_y3TKyNuLTr6OAfMMq5RuVkj0qrfAAyw_9VkYu6IyQL6AGJFQPbTjkalqEgjrwrkhs9M11Qyp7xpcQOKVdx0Ry6HVedFUIpOm1TAgmiM-o50D5UxboWW98tEdL6OGLVYvQZusn9AjNoMl_UuKMhfBGJvYRrxpthrW83o8ttdrpowkgj39PpwjcT-QwR10=w960-h540-no "Team Photo")

Additional photos: https://photos.app.goo.gl/wStjm3jxJ4gyiKRt6

#### **October 27th, 2018** (UAH Space Hardware Club BalloonSat Flight 79)

For our flight on October 10th, 2018, we flew the RAPTOR payload Falcon for the second time. The intent of the flight was to fly on a balloon up to 1000 feet and then release from the balloon. Upon release from the balloon, the payload would drop 10 feet and release a parafoil, beginning guidance toward a designated landing point.

Payload Falcon did not successfully release from the balloon line. Instead it remained attached and flew with the balloon until the balloon’s bursting altitude of approximately 80,000 feet. Upon burst, the payload free-fell until 990 feet and deployed the parafoil, which due to the elevation of the landing sight - was only 300 feet above the ground. The parafoil released from the payload correctly; however, it became entangled in the still-attached balloon line. Although the parafoil was tangled, it slowed the payload down enough that the payload landed safely and was recovered fully intact.

Post flight, through inspecting GoPro footage and the balloon release mechanism, it was discovered that the small line connecting the payload to the balloon line twisted so tightly around the balloon release mechanism release wheel, that the friction between the line and release wheel kept the payload attached to the balloon. In both the video and recorded telemetry data, the release mechanism solenoid was triggered correctly by the Arduino microcontroller.

![alt text](https://lh3.googleusercontent.com/DX8jpagSZ6LKXMaGTUnuR-Gp7IC6Lo57QNAOB3CmmnxLZm5vVSMHzMlLcpr2Hw_cCj3_YJ5Pzvy5XdEeT8kTMvjd3I0hRwUJ8NQtbs2XuicFXm1EfYEKwcU-171ZV9Z0B54OK8CuiAanMtrXleepSJmQGD4R6FtTcWct2zQQi3ftoZOaaSvy5MJd57PklEvV_A1JXkzd3ydmtsylS1GJZnn9lY6fOOgv3TLQNxHcbsMYc0pysnplYyeHI4HfY7fmHPTv4ZAfGTHJ8N8bCBeAc2nUCulA00FgWljDttG_uO51KUS0EKMBc9kD78p773OacAEKI8F68zXOC4yqxvJjxUxC_mN0n1iqWy66CDf-CtKQ5SHZy2SID5FfxAiGVsLxhQ-VDvhNPMOgRIOQVr8bbcuBsayHTS7U8QScCA197ALc4I06pKvjeECXlFBSMk0SJZd68OVwvy5Prsc-uqyJ3VitMfZyhueM1-OnKPLkeqbNlYu5uEHdSnHr4xcAuQ8nG5TSF5dAMJknWnXPoAGkBAfVdaaxsFX6p79kfgIagUZXXE2Ok7Zbl08hZk_G2jK6Ctt8T2--Af-SjBqRRobXrTtietRwmYLaQG3Nd1Pyi7YS51zZN5xO3RkxczHweeLZIBU6GfMnq6NAR4LKoaqRGvLU5FPOLSbUdO1a0zdabKcEHJUvXPVd80EWWN98PEriUAEBxTpp2n1IcdK8Yw64Z9dgJwXpBpaUqzjHygQ=w653-h869-no "Team Photo")

_The small brown line twisted around the mechanism’s paw very tightly._

Even though the payload did not release from the balloon and controlled flight was not achieved, there were still several takeaways from the flight.
First, we learned that the balloon release could fail when the connecting line twisted too many times. We also learned that there was a software design flaw that caused the Arduino to stop writing data to the SD card when the payload was higher than the release altitude. While not intended, we found that our payload is able to fly to high altitudes, not suffer from dropping temperatures, and has enough power to last the duration of the flight. We also learned that, unlike our payload, GoPro cameras can freeze-up at high altitude. On our flight, this caused them to fail and shut down after only ~30 minutes into the flight. Finally, we learned that the parafoil can be safely deployed at terminal velocity (although not ideal) and that the payload box is strong enough to sustain a fast landing.

![alt text](https://lh3.googleusercontent.com/Aypx76Ql5LVa8p2PFBuOJys9CJ3AVa-NEbSdwvvvx31Qhf6bkzXBJTn4RS2yL9QKpeO0D3fYkl0NPFLIo-4bcgZaK_JbQFQ9Q29sOfMKvP4cvz1yX0B2EHW416THLgJkycuDvsOm4I2VyX1KUPI1YrVMiQH4OoqmIukr_5fA7g9JdWdTqVmFvHvDFO-IHRkLT-6SZ9E5tRtIFEBsMk39Tci7O5nE8ahkWd_15v4wlpowVhUSkFwN5wGJxfkjyz0i74V9AmIN5kf_UJ_miloBwVLYJEoVN9yBVm5KRk0qgIhT_WNLKkFmfzpcCLw4_DGleaCtsdwMDb3XgG4PKSPcWFYI5hlyMCP02ln8lC8uz3S3024qQvnta3Q6oxyWaY5JSNhl3uN6x_5Gs-5IV_m70f1my-BGT11xpazVYctbLOWivDNNTjjwqQFMFQEEIEyWKZeDFe3INRJDM600poydtk5qXtPh_WVzQALMXMtAl6uF7a6jhJh70bbQGOlf_orddt-oIjzCxAWZOiIH-5BolxfS3pT80Ie3Gk5S26_v8bNfLM9vdlmndhZPwOBJ_RtREGJupLxx3WK3pn7YvAPnjM4ztzAdFMB1YRgmm8XCQ8IlnJbDDSDE5q2H_XDlah9SgQLAp4zR9zVqF_6nLmtSPKd43-doLY8p6NFxnL67Js1Z-_Gkm6UdrgM7lzBEc2juU-52z621EajiGo-8oW4ZwZZcb7fEKe1lT5UVIOY=w374-h281-no "Team Photo")

Additional photos: https://photos.app.goo.gl/nkUsBDCjjpgs3n9UA
