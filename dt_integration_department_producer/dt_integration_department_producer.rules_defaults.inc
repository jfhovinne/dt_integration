<?php
/**
 * @file
 * dt_integration_department_producer.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dt_integration_department_producer_default_rules_configuration() {
  $items = array();
  $items['rules_dt_integration_department_export'] = entity_import('rules_config', '{ "rules_dt_integration_department_export" : {
      "LABEL" : "Export departments",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "integration_producer", "integration" ],
      "ON" : {
        "node_insert--department" : { "bundle" : "department" },
        "node_update--department" : { "bundle" : "department" }
      },
      "IF" : [ { "node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "integration_producer_rules_action_build_document" : {
            "USING" : { "node" : [ "node" ], "producer" : "department" },
            "PROVIDE" : {
              "document" : { "document" : "Document" },
              "resource_schema" : { "resource_schema" : "Resource schema" }
            }
          }
        },
        { "integration_rules_action_backend_create_document" : {
            "USING" : {
              "backend" : "couchdb",
              "resource_schema" : [ "resource_schema" ],
              "document" : [ "document" ]
            },
            "PROVIDE" : { "integration_document" : { "integration_document" : "Document" } }
          }
        }
      ]
    }
  }');
  return $items;
}
