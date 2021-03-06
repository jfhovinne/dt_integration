<?php
/**
 * @file
 * dt_integration_department_producer.features.inc
 */

/**
 * Implements hook_default_integration_producer().
 */
function dt_integration_department_producer_default_integration_producer() {
  $items = array();
  $items['department'] = entity_import('integration_producer', '{
    "entity_bundle" : "department",
    "backend" : "couchdb",
    "resource" : "departments",
    "settings" : { "plugin" : { "mapping" : {
          "title_field" : "title",
          "field_core_ecorganisation" : "department_type",
          "field_department_dg_type" : "directorate_type",
          "field_department_tasks" : "main_task",
          "field_core_description" : "description",
          "field_core_introduction" : "introduction",
          "field_core_abbreviation" : "abbreviation"
        }
      }
    },
    "name" : "Department",
    "machine_name" : "department",
    "plugin" : "node_producer",
    "enabled" : "1",
    "description" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
