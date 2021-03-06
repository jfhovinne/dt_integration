<?php
/**
 * @file
 * dt_integration_department_consumer.features.inc
 */

/**
 * Implements hook_default_integration_consumer().
 */
function dt_integration_department_consumer_default_integration_consumer() {
  $items = array();
  $items['department'] = entity_import('integration_consumer', '{
    "entity_bundle" : "department",
    "backend" : "couchdb",
    "resource" : "departments",
    "mapping" : [],
    "settings" : { "plugin" : { "mapping" : {
          "title" : "title_field",
          "department_type" : "field_core_ecorganisation",
          "directorate_type" : "field_department_dg_type",
          "main_task" : "field_department_tasks",
          "description" : "field_core_description",
          "introduction" : "field_core_introduction",
          "abbreviation" : "field_core_abbreviation"
        }
      }
    },
    "name" : "Department",
    "machine_name" : "department",
    "plugin" : "node_consumer",
    "enabled" : "1",
    "description" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
