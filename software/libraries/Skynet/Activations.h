//
// Created by trystanmay on 10/30/18.
//

#ifndef SKYNET_ACTIVATIONS_H
#define SKYNET_ACTIVATIONS_H

namespace SkyNet {
	enum Activations {
		Leaky_ReLU, Sigmoid, Softmax
	};

	double activation (const Activations &function, const double &value, const double &sum);
	double activation (const Activations &function, const double &value);

	double activationDerivative (const Activations &function, const double &value, const double &sum);
	double activationDerivative (const Activations &function, const double &value);
}

#endif //SKYNET_ACTIVATIONS_H
