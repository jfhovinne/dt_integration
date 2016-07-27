# Digital Transformation Integration producers and consumers

## Installation

Enable one of the features, depending on the website role (producer or consumer),
for each applicable resource schema.

The related Drupal content-type and fields should already exist in your Drupal instance.

Enable the integration_ui, integration_producer_ui or integration_consumer_ui modules
in order to modify the configuration if needed.

For instance, in order to produce content, you will probably need to authenticate;
update the CouchDB backend login/password fields accordingly.
